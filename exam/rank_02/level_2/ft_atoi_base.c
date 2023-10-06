/*
Takes a string and an int, the string is to be converted to the base indicated by the int.
*/

int	base(int c, int base)
{
	char	*str = "0123456789abcdef";
	char	*str2 = "0123456789ABCDEF";
	int	i = 0;

	while (i < base)
	{
		if (c == str[i] || c == str2[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	nb = 0;
	int	signe;
	int	i = 0;

	if (str[i] == '-' || str[i] == '+')//check the sign of the number
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (base(str[i], str_base) != -1)//iterates until arriving at the end of the string or when meeting a non-valid char
	{
		nb *= str_base;//scale depending on the base
		nb += base(str[i], str_base);//add the char depending on the base
		i++;
	}
	return (nb * signe);
}
