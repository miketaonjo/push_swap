/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:21:15 by mcloarec          #+#    #+#             */
/*   Updated: 2022/07/29 18:48:52 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algo_push_swap(t_stack *stacks)
{
	int	size_stack_a;
	int	i;
	int	bit_int;
	int size_stack_b;

	i = 1;
	bit_int = 32;
	while (i < bit_int)
	{
		size_stack_a = list_size(stacks->a);
		if (check_sort(stacks->a) == 0)
				return ;
		while (size_stack_a > 0)
		{
			if (stacks->a->index >> i & 1)
				ra(stacks->a);
			else
				pb(stacks);
			size_stack_a--;
		}
		size_stack_b = list_size(stacks->b);
		while (size_stack_b > 0)
		{
			pa(stacks);
			size_stack_b--;
		}
		i++;
	}
}

void	algo_for_five(t_stack *stacks)
{
	int		min;
	int		size_stack;
	t_elem	*tmp;

	min = stacks->a->value;
	tmp = stacks->a;
	size_stack = list_size(stacks->a);
	while (tmp->next)
	{
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	if (min > tmp->value)
		min = tmp->value;
	while (min != stacks->a->value)
	{
		if (tmp->index < size_stack / 2)
			rra(stacks->a);
		else
			ra(stacks->a);
	}
	pb(stacks);
	algo_for_four(stacks);
	pa(stacks);
}

void	algo_for_four(t_stack *stacks)
{
	int		min;
	t_elem	*tmp;
	int		size_stack;

	min = stacks->a->value;
	tmp = stacks->a;
	size_stack = list_size(stacks->a);
	while (tmp->next)
	{
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	if (min > tmp->value)
		min = tmp->value;
	while (min != stacks->a->value)
	{
		if (tmp->index < size_stack / 2)
			rra(stacks->a);
		else
			ra(stacks->a);
	}
	pb(stacks);
	algo_for_three(stacks->a);
	pa(stacks);
}

void	algo_for_three(t_elem *list)
{
	if (list->value < list->next->next->value
		&& list->value > list->next->value)
		sa(list);
	else if (list->value > list->next->next->value
		&& list->next->next->value > list->next->value)
		ra(list);
	else if (list->value > list->next->next->value
		&& list->value < list->next->value)
		rra(list);
	else if (list->value < list->next->next->value
		&& list->next->value > list->next->next->value)
	{
		sa(list);
		ra(list);
	}
	else if (list->value > list->next->value
		&& list->next->value > list->next->next->value)
	{
		ra(list);
		sa(list);
	}
}

void	apply_algo(t_stack *stacks)
{
	if (list_size(stacks->a) == 2 && stacks->a->value > stacks->a->next->value)
		swap(stacks->a);
	else if (list_size(stacks->a) == 3)
		algo_for_three(stacks->a);
	else if (list_size(stacks->a) == 4)
		algo_for_four(stacks);
	else if (list_size(stacks->a) == 5)
		algo_for_five(stacks);
	else
		algo_push_swap(stacks);
}
