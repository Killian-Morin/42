#include <stdlib.h>

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

/*
not in grademe but in the exam
A function that removes from the list passed in argument, any element the data of which is equal to the reference data. The function passed in argument takes two void* and returns 0 when both parameters are equal.
*/

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL || *begin_list == NULL)//check if at the end of list
		return ;
  
	t_list	*new = *begin_list;//copy in a single pointer to struct to easily access the member of the struct
	if ((*cmp)(new->data, data_ref) == 0)//both params are equal so this element needs to be removed
	{
		*begin_list = new->next;//the pointer to the list now point to the second element of the original list, since the first element, the one compared is being ignored thanks to this replacement
		free(new);//no leaks with the element that has been ignored/removed
		ft_list_remove_if(begin_list, data_ref, cmp);//recursive with the updated list
	}
	new = *begin_list;//update the pointer to struct since in the if it was possibly updated
	ft_list_remove_if(begin_list, data_ref, cmp);//recursive with the updated list
}
