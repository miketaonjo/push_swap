/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:31:13 by mcloarec          #+#    #+#             */
/*   Updated: 2022/07/30 16:14:47 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	putstr_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	putstr_error_tab(char **argv)
{
	free_tab(argv);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
