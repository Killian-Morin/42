#include <stdlib.h>

/*
idem as ft_range but the attribution of the values are in reverse: begin at end and finish at start.
Needs an ft_absolute().
*/

int	ft_absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	*ft_rrange(int start, int end)
{
	int	size;
	int	*tab;
	int	step;
	int	i;

	size = ft_absolute((end - start)) + 1;
	tab = malloc(sizeof(int) * size);
	if (start > end)
		step = 1;
	else
		step= -1;
	i = 0;
	while (i < size)
	{
		tab[i] = end;//begin at end
		end += step;//depending on the values it does +1 or -1 in order to reach start
		i++;
	}
	return (tab);
}
