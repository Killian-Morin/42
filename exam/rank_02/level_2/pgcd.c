#include <stdio.h>

/*
Take two int in parameters and display their highest common denominator. The highest number that can divide both numbers and leave no rest (nb % z == 0) where z is the potential highest number.
*/

void	pgcd(int a, int b)//the two args has already been converted to int with atoi()
{
	int	z;

	if (a > b)
		z = a;
	else
		z = b;
	while (z > 0)
	{
		if (a % z == 0 && b % z == 0)
		{
			printf("%d", z);
			return ;
		}
		else
			z--;
	}
}
