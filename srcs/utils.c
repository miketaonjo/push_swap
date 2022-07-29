/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:45:43 by mcloarec          #+#    #+#             */
/*   Updated: 2022/07/29 12:27:51 by mcloarec         ###   ########.fr       */
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
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
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
	if (list == NULL)
		return ;
	while (list->prev != NULL)
		list = list->prev;
	while (list)
	{	
		/*ft_printf("[prev]%p\n", list->prev);
		ft_printf("[elem]%p\n", list);
		ft_printf("[next]%p\n", list->next);*/
		ft_printf("index: %d\n", list->index);
		ft_printf("%d\n", list->value);
		list = list->next;
	}
}

t_elem	*last_list(t_elem *list)
{
	if (!list)
		return (0);
	while (list->next)
		list = list->next;
	return (list);
}

int	list_size(t_elem *list)
{
	int	size;

	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}
