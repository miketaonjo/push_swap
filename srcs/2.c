/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:33:31 by mcloarec          #+#    #+#             */
/*   Updated: 2022/07/20 17:35:02 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//libft
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*upgrade;

	new_lst = NULL;
	while (lst)
	{
		upgrade = ft_lstnew(f(lst->content));
		if (!new_cont)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, upgrade);
		lst = lst->next;
	}
	return (new_lst);
}

//check si déja rangée
int	is_sorted(t_elem *list)
{
	while (list->next)
	{
		if (list->value > list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
}


//index
void	assign_index(t_elem *list)
{
	t_stack	*tmp;
	t_stack	*highest;
	int	size_stack;
	int		value;
	
	size_stack = list_size(stacks->a) + 1
	while (--stack_size > 0)
	{
		tmp = list;
		value = INT_MIN;
		highest = NULL;
		while (tmp)
		{
			if (tmp->value == INT_MIN && tmp->index == 0)
				tmp->index = 1;
			if (tmp->value > value && tmp->index == 0)
			{
				value = tmp->value;
				highest = tmp;
				tmp = list;
			}
			else
				tmp = tmp->next;
		}
		if (highest != NULL)
			highest->index = size_stack;
	}
}

//utils
int	sup_all_list(t_list *list)
{
	t_element	*to_del;

	if (list == NULL)
		return (2);
	to_del = list->first;
	while (list->first != NULL)
	{
		list->first = list->first->next;
		free(to_del);
		to_del = list->first;
	}
	free(list);
	list = NULL;
	return (0);
}

t_list	*free_at(t_list *L, int pos)
{
	t_list	*prec;
	t_list	*cur;
	int		i;

	prec = L;
	cur = L;
	if (is_empty_list(L))
		return (NULL);
	if (pos == 0)
	{
		L = L->next;
		free(cur);
		return (L);
	}
	i = 0;
	while (i++ < pos)
	{
		prec = cur;
		cur = cur->next;
	}
	prec->next = cur->next;
	free(cur);
	return (L);
}

t_list	*free_list(t_list *L)
{
	t_list	*tmp;

	tmp = NULL;
	while (L)
	{
		tmp = L->next;
		free(L);
		L = tmp;
	}
	return (L);
}
