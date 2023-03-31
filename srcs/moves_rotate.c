/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vim moves_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:38:22 by mcloarec          #+#    #+#             */
/*   Updated: 2022/07/28 14:40:13 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_elem *list)
{
	rotate(list);
	ft_printf("ra\n");
}

void	rb(t_elem *list)
{
	rotate(list);
	ft_printf("rb\n");
}

void	rra(t_elem *list)
{
	reverse_rotate(list);
	ft_printf("rra\n");
}

void	rrb(t_elem *list)
{
	reverse_rotate(list);
	ft_printf("rrb\n");
}
