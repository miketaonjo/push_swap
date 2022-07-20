/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:33:31 by mcloarec          #+#    #+#             */
/*   Updated: 2022/07/20 17:35:02 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
}	t_stack;

t_list	*new_elem(int n)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = n;
    new->prev = NULL;
	new->next = NULL;
	return (cell);
}

void	print_list(t_list *list)
{
	if (!list)
		ft_printf("NULL\n");
	while (list)
	{
		ft_printf("%d\n", lst->value);
		lst = lst->next;
	}
}

/*t_list	*add_at(t_list *L, int data, int pos)
{
	t_list	*prec;
	t_list	*cur;
	t_list	*cell;
	int		i;

	prec = L;
	cur = L;
	cell = create_cell(data);
	if (is_empty_list(L))
		return (cell);
	if (pos == 0)
	{
		cell->next = L;
		return (cell);
	}
	i = 0;
	while (i++ < pos)
	{
		prec = cur;
		cur = cur->next;
	}
	prec->next = cell;
	cell->next = cur;
	return (L);
}*/

t_list	*add_elem(t_list *lst, int value, int position)
{
	t_list	*new;
	int		i;
    
	new = new_elem(value);
	if (lst == NULL)
		return (new);
	if (position == 0)
	{
		new->next = lst;
		return (new);
	}
	i = 0;
	while (i < position)
	{
		new->prev = lst;
		lst = lst->next;
        i++;
	}
	lst->next = new;
	new->next = lst;
	return (lst);
}

t_list	*parse_list_int(char **argv, t_list	*a)
{
	int		i;
	int		value;

	i = 0;
	while (argv[i])
	{
		if (i == 0)
			i++;
		value = ft_atoli(argv[i]);
		a = add_elem(a, value, i);
		i++;
	}
	print_list(a);
	return (a);
}

t_list	*parse_list_str(char *str, t_list *a)
{
	int		value;
	char	**tab;
	int		i;

	tab = ft_split(str, ' ');
	i = 0;
	while (tab[i])
	{
		value = ft_atoli(tab[i]);
		a = add_elem(a, value, i);
        i++;
	}
	print_list(a);
	return (a);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;

	if (argc == 2)
		a = parse_list_str(argv[1], a);
	if (argc > 2)
		a = parse_list_int(argv, a);
	check_algo(&a, &b);
	printf("list_a:\n");
	print_list(a);
	printf("list_b:\n");
	print_list(b);
	return (0);
}

//moves


void	rotate(t_list **lst)
{
	int	tmp;

	if (!lst)
		exit (0);
	tmp = ((*lst)->value);
	*lst = free_at(*lst, 0);
	*lst = add_at(*lst, tmp, list_len(*lst));
	printf("rr\n");
}

void	reverse_rotate(t_list **list)
{
	int	temp;

	if (!list)
		exit (0);
	temp = get_elem(*list, list_len(*list) - 1);
	*list = free_at(*list, list_len(*list) - 1);
	*list = add_at(*list, temp, 0);
}
