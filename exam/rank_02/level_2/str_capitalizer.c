#include <unistd.h>

/*
Take one or multiple strings, display them with the first letter of a word in uppercase and all the rest in lowercase. Same main() as rstr_capitalizer.
*/

void	str_capitalizer(char *str)
{
	int	i = 0;

	while (str[i])
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))//writes all whitespace from before the words
		{
			write(1, &str[i], 1);
			i++;
		}
		if (str[i] != '\0')//if the string is not finished, we are at the first letter after the whitespace/meaning the first letter of a word and if it is a lowercase, then convert it into uppercase, either way writes the char
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
			write(1, &str[i], 1);
			i++;
		}
		while (str[i] != ' ' && str[i] != '\t' && str[i])//pass through the whole string and if find a uppercase converts it to a lowercase, writes everything
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
			write(1, &str[i], 1);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		int	i = 1;
		while (i != ac)//does all arg
		{
			str_capitalizer(av[i]);
			write(1, "\n", 1);//write a \n between each string
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
