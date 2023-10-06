#include <unistd.h>

/*
Take one or multiple strings, display them with the last letter of a word in uppercase and all the rest in lowercase.
*/

void	rstr_capitalizer(char *str)
{
	int	i = 0;

	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')//writes all whitespace from before the words
		{
			write(1, &str[i], 1);
			i++;
		}
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')//pass through the whole word until meeting a whitespace or the end of the string
		{
			if (str[i] >= 'A' && str[i] <= 'Z' && str[i + 1] != ' ' && str[i + 1] != '\t' && str[i + 1] != '\0')//if a uppercase letter and not the last letter of a word
				str[i] += 32;//converts it to lowercase
			else if ((str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0') && str[i] >= 'a' && str[i] <= 'z')//if a lowercase letter and the last letter of a word
				str[i] -= 32;//converts it to uppercase
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
			rstr_capitalizer(av[i]);
			write(1, "\n", 1);//write a \n between each string
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
