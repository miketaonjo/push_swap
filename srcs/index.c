/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:48:07 by mcloarec          #+#    #+#             */
/*   Updated: 2022/08/04 11:13:29 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	put_index(t_elem *biggest, int n)
{
	if (biggest != NULL)
		biggest->index = n;
}

void	find_biggest(t_elem *list, int size)
{
	t_elem	*tmp;
	t_elem	*biggest;
	int		value;

	while (size-- > 0)
	{
		tmp = list;
		value = INT_MIN;
		biggest = NULL;
		while (tmp)
		{
			if (tmp->value == INT_MIN && tmp->index == -1)
				tmp->index = 1;
			if (tmp->value > value && tmp->index == -1)
			{
				value = tmp->value;
				biggest = tmp;
				tmp = list;
			}
			else
				tmp = tmp->next;
		}
		put_index(biggest, size + 1);
	}
}

void	get_size_stack(t_elem *list)
{
	int	size_stack;

	size_stack = list_size(list);
	find_biggest(list, size_stack);
}
