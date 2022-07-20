/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:45:43 by mcloarec          #+#    #+#             */
/*   Updated: 2022/07/20 14:35:35 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long int	ft_atoli(const char *str)
{
	int			i;
	long int	result;
	int			minus;

	i = 0;
	minus = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * minus);
}

void	print_list(t_elem *list)
{
	while (list->prev != NULL)
		list = list->prev;
	while (list)
	{
		ft_printf("%d\n", list->value);
		list = list->next;
	}
}
