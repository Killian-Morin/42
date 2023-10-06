int	ft_atoi(const char *str)
{
	int	i = 0;
	int	signe = 1;
	int	res = 0;

	if (str[i] == '+' || str[i] == '-')//checks if there is a sign before the number
	{
		if (str[i] == '-')//if it is a minus then setup signe as -1
			signe = -1;
		i++;//iterate to pass the sign
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])//pass all char which are numbers until finding another char or the end of the string
	{
		res *= 10;//add a 0 at the end of the number
		res += str[i] - '0';//converts the number and add its
		i++;
	}
	return (res * signe);//for the possible negative
}
