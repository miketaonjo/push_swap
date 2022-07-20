/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:30:24 by mcloarec          #+#    #+#             */
/*   Updated: 2022/07/20 18:35:34 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_elem *list)
{
	int	tmp;

	if (!list)
		exit (0);
	tmp = list->value;
	list = free_elem(list);
	list = add_elem()
}
