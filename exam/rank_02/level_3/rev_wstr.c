#include <unistd.h>

/*
Takes a string and needs to write its words in reverse order. A word is delimited by whitespaces (spaces/tabs) and the begin/end of the string. 
Needs a ft_strlen() and a ft_putchar.
*/

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int		len;
	char	*str;
	char	*rev;

	if (ac == 2)
	{
		str = av[1];
		len = ft_strlen(av[1]) - 1;//to ignore the last char \0
		rev = NULL;

		while (str[len])//go in reverse
		{
			if (str[len - 1] == ' ' || str[len - 1] == '\t')//if the previous char is a whitespace then we arrived at the end of a word
			{
				rev = &str[len];//copy the string / all the words already passed
				while (*rev && *rev != ' ' && *rev != '\t')//and writes it until meeting a whitespace (end of words and the next words as already been write) or the end of the string (if we are at the first iteration)
				{
					ft_putchar(*rev);
					rev++;
				}
				ft_putchar(' ');//writes a space since we finished a word
			}
			else if (len == 0)//means we are at the first word or at the only word
			{
				rev = &str[len];
				while (*rev && *rev != ' ' && *rev != '\t')//same procedure but we will not writes a space at the end
				{
					ft_putchar(*rev);
					rev++;
				}
			}
			len--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
