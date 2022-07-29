/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:48:07 by mcloarec          #+#    #+#             */
/*   Updated: 2022/07/29 12:42:58 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	put_index(t_elem *list, int n)
{
	if (list != NULL)
			list->index = n;
}

void	find_biggest(t_elem *list)
{
	t_elem	*tmp;
	t_elem	*biggest;
	int		size_stack;
	int		value;

	size_stack = list_size(list) + 1;
	while (--size_stack > 0)
	{
		tmp = list;
		value = INT_MIN;
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
		put_index(biggest, size_stack);
	}
}
