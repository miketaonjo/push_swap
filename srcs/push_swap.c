/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:30:57 by mcloarec          #+#    #+#             */
/*   Updated: 2022/08/04 15:36:52 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int	check_sort(t_elem *list)
{
	t_elem	*tmp;

	tmp = list;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	push_swap(int argc, char **argv)
{
	t_stack	stacks;

	stacks.a = NULL;
	if (argc == 2)
		stacks.a = fill_stack_split(argv[1], stacks.a);
	else
		stacks.a = fill_stack(argv, stacks.a);
	stacks.b = NULL;
	apply_algo(&stacks);
	free_elem(stacks.a);
}

void	check_space(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '\0')
			putstr_error();
		while (argv[i][j] == 32)
		{
			if (argv[i][j + 1] == '\0')
				putstr_error();
			j++;
		}
		i++;
	}
}

void	join_split_arg(int argc, char **argv, int j)
{
	char	*str;
	char	**tab;

	while (argv[j])
	{
		if (*argv[1] == '\0')
			putstr_error();
		check_space(argv);
		if (j == 2)
			str = ft_strjoin_space(argv[1], argv[j], j);
		else
			str = ft_strjoin_space(str, argv[j], j);
		j++;
	}
	tab = ft_split(str, ' ');
	if (!tab[0])
	{
		free(str);
		putstr_error_tab(tab);
	}
	free(str);
	check_arg_split(tab);
	free_tab(tab);
	push_swap(argc, argv);
}
