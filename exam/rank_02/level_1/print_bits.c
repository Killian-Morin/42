/*
Take a byte, prints it in binary | easily testable, just calling the function with a parameter.
*/

void	print_bits(unsigned char octet)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		if (octet & (1 << i))//the & copy the bits common of both elements | the << will add i 0 at the right of the binary of one (0000 0001) | checks if the result of << gives the binary of octet
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i--;
	}
}
