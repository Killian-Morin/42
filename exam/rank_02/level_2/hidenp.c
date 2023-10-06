#include <unistd.h>

/*
if string1 is found in string2 then write 1, else write 0 | found means that each character of string1 is found in string2 in the same order as they appear in string1.
*/

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

int	main(int ac, char **argv)
{
	(void)ac;
	int	i = 0;
	int	k = 0;

	while (i != ft_strlen(argv[2]))//to compare the entirety of string2/argv[2]
	{
		if (argv[1][k] == argv[2][i])//characters = so iterate both strings
		{
			k++;
			i++;
		}
		else//characters ≠ so iterate string2/the string where to find string1
			i++;
	}
	if (k == ft_strlen(argv[1]))//did arrived at the end of string1 / did found every char of string1 in string2 so write 1
		write(1, "1", 1);
	else//didn’t arrived at the end of string1, didn’t find every char of string1 in string2 so write 0
		write(1, "0", 1);
	return (0);
}