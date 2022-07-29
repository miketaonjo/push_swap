/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:15:00 by mcloarec          #+#    #+#             */
/*   Updated: 2022/07/28 15:02:29 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_elem *list)
{
	swap(list);
	ft_printf("sa\n");
}

void	sb(t_elem *list)
{
	swap(list);
	ft_printf("sb\n");
}

void	ss(t_stack *stacks)
{
	if (!stacks->a || !stacks->b || list_size(stacks->a) == 1
		|| list_size(stacks->b) == 1)
		return ;
	swap(stacks->a);
	swap(stacks->b);
	ft_printf("ss\n");
}

void	pa(t_stack *stacks)
{
	t_elem	*old_first;
	t_elem	*new_first;
	t_elem	*old_first_a;

	if (!stacks->b)
		return ;
	new_first = stacks->b->next;
	old_first = stacks->b;
	if (list_size(stacks->a) > 0)
		old_first_a = stacks->a;
	add_elem_front(&stacks->a, old_first);
	if (list_size(stacks->a) > 1)
		old_first_a->prev = old_first;
	stacks->b = new_first;
	//stacks->b->prev = NULL;
	ft_printf("pa\n");
}

void	pb(t_stack *stacks)
{
	t_elem	*old_first;
	t_elem	*new_first;
	t_elem	*old_first_b;

	if (!stacks->a)
		return ;
	new_first = stacks->a->next;
	old_first = stacks->a;
	if (list_size(stacks->b) > 0)
		old_first_b = stacks->b;
	add_elem_front(&stacks->b, old_first);
	if (list_size(stacks->b) > 1)
		old_first_b->prev = old_first;
	stacks->a = new_first;
	stacks->a->prev = NULL;
	ft_printf("pb\n");
}
