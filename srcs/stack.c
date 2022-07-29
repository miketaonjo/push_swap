/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 10:20:14 by mcloarec          #+#    #+#             */
/*   Updated: 2022/07/29 12:39:05 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_elem	*new_elem(int n)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	if (!new)
		return (NULL);
	new->value = n;
	new->index = -1;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	add_elem_front(t_elem **list, t_elem *tmp)
{
	tmp->next = *list;
	tmp->prev = NULL;
	*list = tmp;
}

void	add_elem_back(t_elem **list, int value)
{
	t_elem	*tmp;

	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_elem(value);
	tmp->next->prev = tmp;
	tmp->next->next = NULL;
}

t_elem	*fill_stack(char **argv, t_elem *list)
{
	int		value;
	int		i;

	i = 1;
	list = new_elem(ft_atoli(argv[0]));
	while (argv[i])
	{
		value = ft_atoli(argv[i]);
		add_elem_back(&list, value);
		i++;
	}
	find_biggest(list);
	return (list);
}

t_elem	*fill_stack_split(char *str, t_elem *list)
{
	char	**tab;
	int		value;
	int		i;

	tab = ft_split(str, ' ');
	i = 1;
	list = new_elem(ft_atoli(tab[0]));
	while (tab[i])
	{
		value = ft_atoli(tab[i]);
		add_elem_back(&list, value);
		i++;
	}
	free_tab(tab);
	find_biggest(list);
	return (list);
}
