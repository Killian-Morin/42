/*
Take an unsigned int and determine if it is a power of 2, if yes return 1 else return 0
*/

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	else if (n % 2 == 0 || n == 1)
		return (1);
	return (0);
}

