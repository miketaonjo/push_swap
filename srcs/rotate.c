/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:30:24 by mcloarec          #+#    #+#             */
/*   Updated: 2022/07/29 15:38:45 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_elem *list)
{
	int	tmp;

	if (!list || list_size(list) == 1)
		return ;
	if (list->next != NULL)
	{
		tmp = list->value;
		list->value = list->next->value;
		list->next->value = tmp;
	}
}

void	rotate(t_elem *list)
{
	int	tmp;

	if (!list)
		return ;
	tmp = list->value;
	list->value = list->next->value;
	list->index = list->next->index;
	while (list->next)
	{
		list->value = list->next->value;
		list->index = list->next->index;
		list = list->next;
	}
	list->value = tmp;
}

void	rr(t_stack *stacks)
{
	if (!stacks->a || !stacks->b)
		return ;
	rotate(stacks->a);
	rotate(stacks->b);
	ft_printf("rr\n");
}

void	reverse_rotate(t_elem *list)
{
	int	tmp;

	while (list->next)
		list = list->next;
	tmp = list->value;
	while (list->prev)
	{
		list->value = list->prev->value;
		list = list->prev;
	}
	list->value = tmp;
}

void	rrr(t_stack	*stacks)
{
	if (!stacks->a || !stacks->b)
		return ;
	reverse_rotate(stacks->a);
	reverse_rotate(stacks->b);
	ft_printf("rrr\n");
}
