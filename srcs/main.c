/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:42:55 by mcloarec          #+#    #+#             */
/*   Updated: 2022/08/04 15:36:29 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	char	**tab;
	int		j;

	if (argc < 2)
		exit (0);
	else if (argc == 2)
	{
		if (*argv[1] == '\0')
			putstr_error();
		tab = ft_split(argv[1], ' ');
		if (!tab[0])
			putstr_error_tab(tab);
		check_arg_split(tab);
		free_tab(tab);
		push_swap(argc, argv);
	}
	else
	{
		j = 2;
		join_split_arg(argc, argv, j);
	}
}
