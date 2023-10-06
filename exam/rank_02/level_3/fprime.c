#include <stdio.h>

/*
Takes a number and needs to display its prime factors. 
Needs an is_prime().
*/

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
	if (ac == 2)
	{
		int	nb = atoi(av[1]);//convert the arg
		int	first = 1;//signal for printing a * before the factor
		int	factor = 2;

		if (nb == 1)//particular case for 1 since doesn’t work with the normal case
			printf("1");
		while (factor <= nb)//tries all the numbers until the arg itself
		{
			if (nb % factor == 0 && is_prime(factor))//if the nb is divisible by the factor and the factor is prime, then its a prime factor
			{
				if (first == 1)//first iteration and the first factor so no *
					printf("%d", factor);
				else
					printf("*%d", factor);//also prints the * before the factor
				nb /= factor;//update the nb to leave what has been cleared by the factor
				first = 0;//change first after the first iteration to always put an * before the new added factor
			}
			else
				factor++;
		}
	}
	printf("\n");
	return (0);
}
