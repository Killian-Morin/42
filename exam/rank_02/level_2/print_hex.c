#include <unistd.h>

/*
Takes a positive (including 0) number in base 10 and writes it in base 16 (lowercase letters). 
Need a simplified ft_atoi. The function is similar to ft_putnbr().
*/

void	print_hex(int nb)
{
	char	*str = "0123456789abcdef";//the chars available in the hexadecimal base

	if (nb >= 16)//if isn’t in the scope of the hexadecimal base
		print_hex(nb / 16);//recursive with the nb / 16
	write(1, &str[nb % 16], 1); //while the modulo is used to find the corresponding char in the available char of the hexadecimal base
}
