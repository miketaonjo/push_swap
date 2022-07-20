/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:42:55 by mcloarec          #+#    #+#             */
/*   Updated: 2022/07/20 18:42:22 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_stack	*stacks;

	stacks = malloc(sizeof(t_stack));
	stacks->a = malloc(sizeof(t_elem));
	stacks->b = malloc(sizeof(t_elem));
	if (!stacks || !stacks->a || !stacks->b)
		return ;
	if (argc == 2)
		stacks->a = fill_stack_split(argv[1], stacks->a);
	else
		stacks->a = fill_stack(argv, stacks->a);
}

int	main(int argc, char **argv)
{
	char	**tab;

	if (argc < 2)
		exit (0);
		//putstr_error();
	else if (argc == 2)
	{
		if (*argv[1] == '\0')
			putstr_error();
		tab = ft_split(argv[1], ' ');
		if (!tab[0])
		{
			free_tab(tab);
			putstr_error();
		}
		check_arg(tab);
		free_tab(tab);
	}
	else
		check_arg(++argv);
	push_swap(argc, argv);
}
