#include <stdlib.h>

/*
Allocate an array of int, fill it with consecutive values that begin at start and finish at end (including both).
Needs an ft_absolute().
*/

int	ft_absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	*ft_range(int start, int end)
{
	int	i;
	int	step;
	int	size;
	int	*tab;

	size = ft_absolute((end - start)) + 1;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (tab);
	i = 0;
	if (start > end)
		step = -1;
	else
		step = 1;
	while (i < size)
	{
		tab[i] = start;//begin at start
		start += step;//depending on the values it does +1 or -1 in order to reach start
		i++;
	}
	return (tab);
}
