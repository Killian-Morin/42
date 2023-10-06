#include <unistd.h>
#include <stdlib.h>

/*
Takes an int and converts it to a null-terminated string, the string is in an allocated char *.
Need a ft_absolute().
*/

int	ft_absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_len(int n)//return the len of the nb (the minus is take in account if negative number)
{
	int	len = 0;

	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int		len;
	char	*res;

	len = ft_len(nbr);
	res = malloc(sizeof(res) * (len + 1));//+1 for the null-terminating
	if (!res)
		return (NULL);
	res[len--] = '\0';//null-terminating the string
	if (nbr == 0)
		res[0] = '0';//particular management for the 0
	else if (nbr < 0)
		res[0] = '-';//if negative, put the minus at the start of string
	while (nbr != 0)//going backwards with the numbers
	{
		res[len--] = ft_absolute(nbr % 10) + '0';//put the absolute modulo (allow to deal with the negatives with just that) of the nbr in the string
		nbr /= 10;//and decrement the string by clearing the precedent digit
	}
	return (res);
}
