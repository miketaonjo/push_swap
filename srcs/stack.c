/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 10:20:14 by mcloarec          #+#    #+#             */
/*   Updated: 2022/08/04 14:28:55 by mcloarec         ###   ########.fr       */
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
	int		i;
	int		j;
	char	*str;

	i = 1;
	j = i + 1;
	while (argv[j])
	{
		if (i == 1)
		{
			str = ft_strjoin_space(argv[1], argv[j], j);
			i++;
		}
		else
			str = ft_strjoin_space(str, argv[j], j);
		j++;
	}
	list = fill_stack_split(str, list);
	free(str);
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
	get_size_stack(list);
	return (list);
}
