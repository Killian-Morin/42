#include <unistd.h>

/*
	Write a function that sorts the list passed as an parameter, using the function pointer cmp to sort the list depending on the function (increasing/decreasing). Function passed as cmp, if a<b return a value ≠ 0 else return 0
	Testing this function is also pretty hard.
	The function passed in argument does not need to be defined in the code.
*/

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*new;
	int		signal;
	int	temp;

	new = lst;
	signal = 1;
	while (signal == 1)
	{
		signal = 0;//if we checked the whole lst and signal did not change, this means that we did not swapped value, thus lst is already in order, thus we can quit the loop and return lst
    	while (new != NULL && new->next != NULL)//to iterate through the whole list
    	{
			if (cmp(new->data, new->next->data) == 0)//check the return value of the function passed in parameter, if not in the right order (return 0) then swap value
			{
				temp = new->next->data;//exchange the value
				new->next->data = new->data;
				new->data = temp;
				signal = 1;//we swapped a value, the list was not sorted so we reinitialize signal for doing another iteration to check if the list is now sorted
			}
			new = new->next;//pass to the next link
		}
		new = lst;
	}
	return (lst);
}
