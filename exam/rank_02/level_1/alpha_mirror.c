#include <unistd.h>

/*
Takes a string and writes it after replacing each alphabetical character by the opposite alphabetical character (a -> z | M -> N)
*/
int main(int ac, char **av)
{
	int i = 0;

	if (ac == 2)
	{
		while(av[1][i]) 
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
				av[1][i] = 219 - av[1][i];//the formula to do
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				av[1][i] = 155 - av[1][i];//the formula to do
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write (1,"\n",1);
	return (0);
}	