#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/*
	PASSE grademe
*/

/* function to write an error message to standard error (file descriptor 2) */
void	str_write(char *str)
{
	int	i = 0;

	while (str[i])
		write(2, &str[i++], 1);
}

/* function specialy for the fatal error (to clarify the code and reducing lines) */
void	error_fatal(void)
{
	str_write("error: fatal\n");
	exit(1);
}

/* function to change the current directory */
int	cd(int i, char **av)
{
	if (i != 2)
	{
		str_write("error: cd: bad arguments\n");
		return (1);//return an error if the number of arguments is not the right one (2)
	}
	if (chdir(av[1]) == -1)
	{
		str_write("error: cd: cannot change directory to ");
		str_write(av[1]);
		str_write("\n");
		return (1);//return an error if directory change fails
	}
	return (0);//return 0 on success
}

/* function to execute a command */
int	exec(int i, char **av, char **env)
{
	pid_t	pid;
	int		fd[2];
	int		pipe_signal = 0;

	if (av[i])//if the command is not NULL
	{
		if (!strcmp(av[i], "|"))//if the command is indeed a |, we set the signal to 1, that way it will do all conditions concerning the pipe
			pipe_signal = 1;
	}
	if (pipe_signal)//when in a pipe, we pipe()
	{
		if (pipe(fd) == -1)
			error_fatal();//return an error if pipe creation fails
	}
	pid = fork();//create a child process
	if (pid == -1)
		error_fatal();
	else if (pid == 0)
	{
		av[i] = 0;//set the element after the pipe or semicolon to 0
		if (pipe_signal)//when in a pipe, we change the stdout by the one of the pipe and close the fd not used
		{
			if (dup2(fd[1], 1) == -1)
				error_fatal();
			if (close(fd[1]) == -1 || close(fd[0]) == -1)
				error_fatal();
			//exit the program if pipe redirection or closing fails
		}
		if (execve(*av, av, env) == -1)//execute the command
		{
			str_write("error: cannot execute ");
			str_write(*av);
			str_write("\n");
			return (1);//return an error if execution fails
		}
	}
	waitpid(pid, NULL, 0);//wait for the child process to finish
	if (pipe_signal)//when in a pipe, we change the stdin by the one of the pipe and close the fd not used
	{
		if (dup2(fd[0], 0) == -1)
			error_fatal();
		if (close(fd[1]) == -1 || close(fd[0]) == -1)
			error_fatal();
		//exit the program if pipe redirection or closing fails
	}
	return (0);//also work by using WIFEXITED and WEXITSTATUS with as arg, the status of the waitpid for the child
}

int	main(int ac, char **av, char **env)
{
	int	i = 0;
	int	res = 0;

	if (ac > 1)
	{
		while (av[i] && av[++i])
		{
			av += i;//move the av pointer forward by i, the number of av passed in the previous execution
			i = 0;
			while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
				i++;//iterate until finding a '|' or a ';' or the last arg
			if (!strcmp(*av, "cd"))
				res = cd(i, av);//execute cd command
			else if (i)
				res = exec(i, av, env);//execute other commands
		}
	}
	return (0);//return the status of the last executed command
}
