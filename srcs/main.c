/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:42:55 by mcloarec          #+#    #+#             */
/*   Updated: 2022/07/29 18:31:36 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//pour tester les moves
t_elem	*create_stack_b(t_elem *list)
{
	int	tab[4] = {4, 8, 9, 2};
	int	i;

	i = 1;
	list = new_elem(tab[0]);
	while (i < 4)
	{
		add_elem_back(&list, tab[i]);
		i++;
	}
	print_list(list);
	return (list);
}

int	check_sort(t_elem *list)
{
	t_elem	*tmp;

	tmp = list;
	while (tmp)
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

	//stacks = malloc(sizeof(t_stack));
	//stacks->a = malloc(sizeof(t_elem));
	//stacks->b = malloc(sizeof(t_elem));
	//if (!stacks || !stacks->a /*|| !stacks->b*/)
	//	return ;
	stacks.a = NULL;
	if (argc == 2)
		stacks.a = fill_stack_split(argv[1], stacks.a);
	else
		stacks.a = fill_stack(argv, stacks.a);
	stacks.b = NULL;
	//stacks->b = create_stack_b(stacks->b);// pour tester les moves
	apply_algo(&stacks);
	//free_elem(stacks.a);
	print_list(stacks.a);
	/*ft_printf("**********\n");
	print_list(stacks->b);*/
}

int	main(int argc, char **argv)
{
	char	**tab;

	if (argc < 2)
		exit (0);
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
		check_arg_split(tab);
		free_tab(tab);
	}
	else
		check_arg(++argv);
	push_swap(argc, argv);
}
