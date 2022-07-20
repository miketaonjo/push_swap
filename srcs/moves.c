/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:15:00 by mcloarec          #+#    #+#             */
/*   Updated: 2022/07/20 18:38:10 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_elem *list)
{
	int	tmp;
	
	if (list->value && list->next != NULL)
	{
		tmp = list->value;
		list->value = list->next->value;
		list->next->value = tmp;
	}
}

void	ss(t_stack *stacks)
{
	swap(stacks->a);
	swap(stacks->b);
	ft_printf("ss\n");
}

void	pa(t_elem *list_a, t_elem *list_b)
{
	if (!list_b)
		exit (0);
	list_a = add_elem(list_a, list_b->value);
	//list_b = free_elem(list_b);
	ft_printf("pa\n");
}

void	pb(t_elem *list_a, t_elem *list_b)
{
	if (!list_a)
		exit (0);
	list_b = add_elem(list_b, list_a->value);
	//list_a = free_elem(list_a);
	ft_printf("pb\n");

}
