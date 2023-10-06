/*
Takes two unsigned int and returns their lowest common multiple. The smallest positive number that can divide both numbers and leave no rest (z % nb == 0), this number is greater than both multipliers.
*/

unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)//if one the two unsigned int = 0 then 0
		return (0);

	unsigned int	n;
	if (a > b)
		n = a;
	else
		n = b;
	while (1)//until arriving on a int that check the condition
	{
		if (n % a == 0 && n % b == 0)//if both int can be divided then it is the number
			return (n);//return as soon as the int is found since its the lowest since we increase n
		++n;
	}
}
