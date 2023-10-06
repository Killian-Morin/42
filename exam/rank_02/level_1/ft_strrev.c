/*
Take a string in parameter and reverse it (in-place), it returns this reversed string.
*/

char	*ft_strrev(char *str)
{
	int		i = 0;
	int		len = 0;
	char	tmp;

	while (str[len])//get the length of str
		len++;
	len--;//ignore the last char: \0
	while (i < len / 2)//swap the char until the middle of the string
	{
		tmp = str[i];//ex: first iteration -> get the first char
		str[i] = str[len - i];//ex: first char -> get the last char
		str[len - i] = tmp;//ex: last char -> get the first char stored in tmp
		i++;
	}
	return (str);
}
