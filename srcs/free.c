/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:35:15 by mcloarec          #+#    #+#             */
/*   Updated: 2022/07/28 17:51:00 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_elem(t_elem *list)
{
	t_elem	*tmp;

	if (list->prev != NULL)
		list = list->prev;
	while (list->next)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	free(list);
}
