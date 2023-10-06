/*
Take a byte, swaps its halves and return the result | the bits of the right part of octet is passed to the left part and the left part of the bits are passed to the right parts.
*/

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}
