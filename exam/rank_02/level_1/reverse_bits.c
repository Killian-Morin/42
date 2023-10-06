/*
Take a byte, reverse it, bit by bit and return the result.
https://github.com/agavrel/42-Bitwise_Operators/blob/master/1.2_reverse_bits.c 
Similar to ft_atoi, scale the res with the base (here 2) and then add the octet % 2, then divide octet with the base (here 2).
*/

unsigned char	reverse_bits(unsigned char octet)
{
	int				i = 8;
	unsigned char	res = 0;

	while (i > 0)//since the octet is 8 bytes, 8 iterations
	{
		res *= 2;//*2 since in base 2
		res += octet % 2;//get either 0 or 1 for the bits
		octet /= 2;//divide octet to erase the bit located on the extreme right of octet. octet /= 2 is equivalent to b >>= 1, and /2 since in base 2
		i--;
	}
	return (res);
}
