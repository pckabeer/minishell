#include "minishell.h"


t_dlist	*ft_dlstnew(char *data)
{
	t_dlist	*element;

	element = malloc(sizeof(t_dlist));
	if (element == NULL)
		return (0);
	element -> content = data;
	element -> next = NULL;
	element -> prev = NULL;
	return (element);
}

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	if (*lst)
	{
		new->prev = ft_dlstlast(*lst);
		ft_dlstlast(*lst)->next = new;
	}
	else
		*lst = new;
}

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	if (*lst)
		(*lst)->prev = new;
	new->next = *lst;
	new -> prev = NULL;
	*lst = new;
}

int	ft_dlstsize(t_dlist *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_dlstclear(t_dlist **lst)
{
	t_dlist	*n_lst;

	while (*lst)
	{
		n_lst = *lst;
		*lst = n_lst -> next;
		free(n_lst);
	}
}

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		lst = lst->next;
	}
	return (lst);
}