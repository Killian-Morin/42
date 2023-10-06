#include <unistd.h>

/*
Takes an int and returns the sum of all prime numbers <= to the int passed in arguments.
Needs a simplified ft_atoi (that manages only positive numbers), is_prime and ft_putnbr (simplified version).
*/

int	ft_atoi(char *str)
{
	int	res = 0;

	while (*str >= '0' && *str <= '9')
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	return (res);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	char c = (n % 10) + '0';
	write(1, &c, 1);
}

int	is_prime(int n)//a prime number can be divisible only by 1 and itself, so the result of modulo of this number with every number smaller than him (and ignoring 2) will not be 0
{
	int	i = 2;

	while (i < n)//check all numbers before the number that is check and if the modulo is 0 then i is a divisible so not a prime number
	{
		if (n % i == 0)//not a prime number so return (0);
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 2 && ft_atoi(av[1]) > 0)
	{
		int	nb = ft_atoi(av[1]);
		int	sum = 0;
		int	factor = 2;//ignore 0 and 1 to evitate those prime

		while (factor <= nb)
		{
			if (is_prime(factor) == 1)//if factor is prime, return 1 else return 0
				sum += factor;
			factor++;
		}
		ft_putnbr(sum);
	}
	else
		ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}
