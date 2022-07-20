/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 10:20:14 by mcloarec          #+#    #+#             */
/*   Updated: 2022/07/20 16:10:40 by mcloarec         ###   ########.fr       */
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
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_elem    *add_elem(t_elem *list, int value)
{
    while (list->next)
        list = list->next;
    list->next = new_elem(value);
    list->next->prev = list;
    list->next->next = NULL;
	return (list);
}

/*t_elem	*add_elem(t_elem *list, int value)
{*
	t_elem	*new;

	new = new_elem(value);
	if (list == NULL)
		return (new);
	while (list->next != NULL)
		list = list->next;
	new->prev = list;
	list->next = new;
	new->next = NULL;
	return (list);
}*/

t_elem	*fill_stack(char **argv, t_elem *list)
{
	int	value;
	int	i;

	i = 1;
	list = new_elem(ft_atoli(argv[0]));
	while (argv[i])
	{
		value = ft_atoli(argv[i]);
		list = add_elem(list, value);
		i++;
	}
	print_list(list);
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
	//free(tab[0]);
	while (tab[i])
	{
		value = ft_atoli(tab[i]);
		list = add_elem(list, value);
		//free(tab[i]);
		i++;
	}
	free_tab(tab);
	print_list(list);
	return (list);
}
