#include <unistd.h>

/*
Take two strings and if it’s possible to write the first string with characters from the second string, while respecting the order in which these characters appear in the second string, write it.
*/

void	ft_putstr(char *str)
{
	int	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	main(int ac, char **av)
{
	int	j = 0;
	int	i = 0;

	if (ac == 3)
	{
		while (av[2][j])//parse the whole set of char available to write the word/av[1]
		{
			if (av[2][j++] == av[1][i])//iterate the set of char and if a char is one from the word to write, then pass to the next char of the word
				i++;
		}
		if (!av[1][i])//if we arrive at the end of the word to write after the while, it means that we found all char needed, so we can write the word
			ft_putstr(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
