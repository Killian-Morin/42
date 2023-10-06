/*
not in grademe but in the exam
Similar to ft_lstiter() from the bonus of libft
*/

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*new;

	new = begin_list;//copy the list
	while (new)//iterates through the whole list
	{
		(*f)(new->data);//apply the function with the data of the current node of the list
		new = new->next;//pass to the next node of the list
	}
}
