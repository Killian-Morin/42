/*
not in grademe but in the exam
Function that sort (in-place) tab, that contains exactly size members, in ascending order. Input is coherent and doubles are not a problem.
*/

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	int				tmp;

	if (size != 0)
	{
		while (i < size)//iterates until the size for i members of tab
		{
			if (tab[i] > tab[i + 1])//if a member is greater than the next one in the tab, then need to swap their value
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				i = 0;//restart the comparison at 0
			}
			else
				i++;
		}
	}
}
