#include <unistd.h>

/*
Take two strings and display without doubles, the characters that appear in both strings, in the order they appear in the first one.
*/
int	main(int ac, char **av)
{
	int	i;
	int	l;
	int	k;

	if (ac == 3)
	{
		i = 0;
		while (av[1][i])//iterates through the whole first arg/string
		{
			k = 0;
			while (av[2][k])//iterates through the whole second arg/string
			{
				if (av[1][i] == av[2][k])//if the char is identical, we need to check if the char is already present in one of the two strings before his position
				{
					l = 0;
					while (av[1][l] != av[1][i])//resume a the start of the first string to check if the char is already present before in the string
						l++;
					if (l == i)//at the same index so no duplicate so we can check if the char is already present in the second string
					{
						l = 0;
						while (av[2][l] != av[2][k])//resume a the start of the second string to check if the char is already present before in the string
							l++;
						if (l == k)//at the same index, so no duplicate in either the first or second string so write this char
							write(1, &av[1][i], 1);
					}
				}
				k++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
