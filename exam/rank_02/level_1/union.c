/*
Takes two strings and write all unique characters in each string without repetition, within a string and within both, meaning that if a char is present in both strings, it is not written.
*/

int	ft_verif_char(char *str, char c, int index)//check if the char c is present in str until index to not pass the char that is compared to the string
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void    ft_union(char *s1, char *s2)
{
	int	i;
	int	len;

	i = 0;
	while (s1[i])//iterates through the first string
	{
		if (ft_verif_char(s1, s1[i], i) == 1)//check if the char is a duplicate in s1/av[1] until the current index/the current char
			write(1, &s1[i], 1);
		i++;
	}
	len = i;//len of s1
	i = 0;
	while (s2[i])//iterates through the second string
	{
		if (ft_verif_char(s2, s2[i], i) == 1)//check if the char is a duplicate in s2/av[2] until the current index/the current char
		{
			if (ft_verif_char(s1, s2[i], len) == 1)//check if the char found in s2/av[2] is present in the entirety of s1/av[1], thus the len to check the whole string
				write(1, &s2[i], 1);
		}
		i++;
	}
}
