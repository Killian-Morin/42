#include <stdio.h>
#include <stdlib.h>

//essayer de voir si possible de faire genre: stack_a[0] < stack[1] < stack[2] pour remplacer condition if ligne 19 mais arrive pas à faire un main correct

void	sort_three_element(int *stack_a)
{
	//stack_a[0] est le min: 1 2 3 ou 1 3 2
	if (stack_a[0] < stack_a[1] && stack_a[0] < stack_a[2])
	{
		//1 2 3, déjà croissants
		if (stack_a[1] < stack_a[2])
			printf("\n");
		//1 3 2, monter le max puis le mettre dernier
		else if (stack_a[1])
			printf("%s\n%s\n", "sa", "ra");
	}
	//stack_a[1] est le min: 2 1 3 ou 3 1 2
	else if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2])
	{
		//2 1 3, le max est le der dc intervertit l'element 0 et l'element 1
		if (stack_a[0] < stack_a[2])
			printf("%s\n", "sa");
		//3 1 2, le max est l'element 0 dc on le met à la fin
		else
			printf("%s\n", "ra");
	}
	//stack_a[2] est le min: 2 3 1 ou 3 2 1
	else if (stack_a[0] > stack_a[2] && stack_a[1] > stack_a[2])
	{
		//2 3 1, monter le min à la 1ere place
		if (stack_a[0] < stack_a[1])
			printf("%s\n", "rra");
		//3 2 1, intervertir l'element 0 avec l'element 1 puis monter le min à la 1ere place
		else
			printf("%s\n%s\n", "sa", "rra");
	}
}

// int main(void)
// {
//     int *tab = NULL;

//     tab[0] = 2;
//     tab[1] = 1;
//     tab[2] = 3;
//     sort_three_element(tab);
//     return (0);
// }

int    main(int argc, char **argv)
{
    int *tab = NULL;
    int i = 1;
    int j = 0;

    while (i != argc)
    {
        tab[j] = *argv[i];
        i++;
        j++; 
    }
    sort_three_element(tab);
    return (0);
}