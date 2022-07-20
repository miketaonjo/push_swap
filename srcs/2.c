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

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = empty_list();
	list_b = empty_list();
	if (argc == 1)
		ft_error();
	if (argc == 2)
		list_a = parse_list_str(argv[1], list_a);
	if (argc > 2)
		list_a = parse_list_int(argv, list_a);
	/*printf("--->%d\n", list_len(list_a));
	push(&list_a, &list_b);
	swap(&list_a);
	push(&list_a, &list_b);
	rotate(&list_a);
	reverse_rotate(&list_b);*/
	check_algo(&list_a, &list_b);
	printf("list_a:\n");
	print_list(list_a);
	printf("list_b:\n");
	print_list(list_b);
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

//algo
int	check_algo(t_list **list_a, t_list **list_b)
{
	if (list_len(*list_a) == 2 && (*list_a)->data > (*list_a)->next->data)
		swap(list_a);
	if (list_len(*list_a) == 3)
		small_algo(list_a);
	if (list_len(*list_a) == 5)
		med_algo(list_a, list_b);
	return (0);
}

void	small_algo(t_list **list)
{
	if ((*list)->next->data < (*list)->data
		&& (*list)->data < (*list)->next->next->data)
		swap(list);
	if ((*list)->next->next->data < (*list)->next->data
		&& (*list)->next->data < (*list)->data)
	{
		rotate(list);
		swap(list);
	}
	if ((*list)->next->data < (*list)->next->next->data
		&& (*list)->next->next->data < (*list)->data)
		rotate(list);
	if ((*list)->data < (*list)->next->next->data
		&& (*list)->next->next->data < (*list)->next->data)
	{
		swap(list);
		rotate(list);
	}
	if ((*list)->next->next->data < (*list)->data
		&& (*list)->data < (*list)->next->data)
		reverse_rotate(list);
}

void	check_elem(t_list **list_a, t_list **list_b)
{
	int	temp;
	int	i;
	
	if ((*list_a)->data > (*list_a)->next->data)
	{
		i = 1;
		temp = (*list_a)->data;
		while (temp > get_elem(*list_a, i) || i == list_len(*list_a))
		{
			i++;
			if (i == list_len(*list_a))
				break ;
		}
		*list_a = free_at(*list_a, 0);
		*list_a = add_at(*list_a, temp, i - 1);
	}
}

void	med_algo(t_list **list_a, t_list **list_b)
{
	push(list_a, list_b);
	push(list_a, list_b);
	check_algo(list_a, list_b);
	push(list_b, list_a);
	check_elem(list_a, list_b);
	push(list_b, list_a);
	check_elem(list_a, list_b);
}

//utils

int	list_len(t_list *L)
{
	int	i;

	i = 0;
	while (L)
	{
		i++;
		L = L->next;
	}
	return (i);
}

t_list	*free_at(t_list *L, int pos)
{
	t_list	*prec;
	t_list	*cur;
	int		i;

	prec = L;
	cur = L;
	if (is_empty_list(L))
		return (NULL);
	if (pos == 0)
	{
		L = L->next;
		free(cur);
		return (L);
	}
	i = 0;
	while (i++ < pos)
	{
		prec = cur;
		cur = cur->next;
	}
	prec->next = cur->next;
	free(cur);
	return (L);
}

t_list	*free_list(t_list *L)
{
	t_list	*tmp;

	tmp = NULL;
	while (L)
	{
		tmp = L->next;
		free(L);
		L = tmp;
	}
	return (L);
}

int		get_elem(t_list *L, int pos)
{
	int	i;

	i = 0;
	if (pos > list_len(L))
	{
		printf("print_elem : position given higher than length of list...\n");
		exit (0);
	}
	while (i < pos)
	{
		i++;
		L = L->next;
	}
	return (L->data);
}
