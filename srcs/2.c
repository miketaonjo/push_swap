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

//libft
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*upgrade;

	new_lst = NULL;
	while (lst)
	{
		upgrade = ft_lstnew(f(lst->content));
		if (!new_cont)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, upgrade);
		lst = lst->next;
	}
	return (new_lst);
}

//afficher msg
void	ra(t_node **stack_a)
{
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
}

//algo
int	min(t_node **stack, int number)
{
	t_node	*head;
	int		min_index;

	head = *stack;
	min_index = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min_index) && head->index != number)
			min_index = head->index;
	}
	return (min_index);
}

// Renvoie la distance entre la node initiale et celle ayant l'index cherché
int	get_distance_node(t_node **stack, int index)
{
	t_node	*head;
	int		distance_node;

	distance_node = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance_node++;
		head = head->next;
	}
	return (distance_node);
}

void	algo_for_four(t_node **stack_a, t_node **stack_b)
{
	int	distance;

	distance = get_distance_node(stack_a, min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (stack_is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_b, stack_a);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	distance;

	distance = get_distance_node(stack_a, min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (stack_is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_b, stack_a);
}

//check si déja rangée
int	is_sorted(t_elem *list)
{
	t_elem	*tmp;
	
	tmp = list;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// Tri radix des valeurs par indexion binaire
void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = ft_stack_size(*stack_a);
	while (!stack_is_sorted(stack_a))
	{
		j = 0;
		while (j++ < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_stack_size(*stack_b) != 0)
			pa(stack_b, stack_a);
		i++;
	}
}

//index
t_node	*create_node(int number)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node -> number = number;
	new_node -> index = -1;
	new_node -> next = NULL;
	return (new_node);
}

// Renvoie la prochaine valeur minimale de la stack
t_elem	*get_next_min(t_elem *list)
{
	t_elem	*tmp;
	t_elem	*min;
	int	minimum;

	min = NULL;
	minimum = 0;
	tmp = list;
	while (tmp->next)
	{
		if ((tmp->index == -1) && (!minimum || tmp->value < min->value))
		{
			min = tmp;
			minimum = 1;
		}
		tmp = tmp->next;
	}
	return (min);
}

// Attribue leur index aux nodes de la stack lors de l'initialisation
void	put_index(t_elem *list)
{
	t_elem	*tmp;
	int		index;

	index = 0;
	tmp = get_next_min(&list);
	while (tmp->next)
	{
		tmp->index = index++;
		tmp = get_next_min(&list);
	}
}

void	assign_index(t_elem *list)
{
	t_stack	*tmp;
	t_stack	*highest;
	int	size_stack;
	int		value;
	
	size_stack = list_size(stacks->a) + 1
	while (--stack_size > 0)
	{
		tmp = list;
		value = INT_MIN;
		highest = NULL;
		while (tmp)
		{
			if (tmp->value == INT_MIN && tmp->index == 0)
				tmp->index = 1;
			if (tmp->value > value && tmp->index == 0)
			{
				value = tmp->value;
				highest = tmp;
				tmp = list;
			}
			else
				tmp = tmp->next;
		}
		if (highest != NULL)
			highest->index = size_stack;
	}
}

//utils
void	free_stack(t_elem *list)
{
	t_elem	*lst;
	t_elem	*tmp;

	lst = list;
	while (lst->next)
	{
		tmp = lst;
		lst = lst ->next;
		free(tmp);
	}
	free(list);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
