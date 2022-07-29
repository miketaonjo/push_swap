/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:43:08 by mcloarec          #+#    #+#             */
/*   Updated: 2022/07/29 14:09:32 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stddef.h>
# include<limits.h>
# include<string.h>
# include"libft/libft.h"

/* Structure représentant un élément de la liste */
typedef struct s_elem
{
	int				value;
	int				index;
	struct s_elem	*prev;
	struct s_elem	*next;
}					 t_elem;

/* Structure qui contient les 2 piles */
typedef struct s_stack
{
	t_elem	*a;
	t_elem	*b;
}				t_stack;

/* Main bis */
void	push_swap(int argc, char **argv);

/* Check arguments */
void	check_arg(char **argv);
void	check_arg_split(char **argv);
int		check_nb(char *str);
int		check_duplicata(char **argv);
int		nb_comp(long n1, long n2);
int		check_sort(t_elem *list);

/* Free & Error */
void	free_tab(char **tab);
void	free_elem(t_elem *list);
void	putstr_error(void);

/* Utils */
long int	ft_atoli(const char *str);
void	print_list(t_elem *list);
t_elem	*last_list(t_elem *list);
int		list_size(t_elem *list);

/* Remplir pile A */
t_elem	*fill_stack_split(char *str, t_elem *list);
t_elem	*fill_stack(char **argv, t_elem *list);
void	add_elem_back(t_elem **list, int value);
void	add_elem_front(t_elem **list, t_elem *tmp);
t_elem	*new_elem(int n);
void	find_biggest(t_elem *list);
void	put_index(t_elem *list, int n);

/* Moves */
void	swap(t_elem *list);
void	sa(t_elem *list);
void	sb(t_elem *list);
void	ss(t_stack *stacks);
void	pa(t_stack *stacks);
void	pb(t_stack *stacks);
void	rotate(t_elem *list);
void	ra(t_elem *list);
void	rb(t_elem *list);
void	rr(t_stack *stacks);
void	reverse_rotate(t_elem *list);
void	rra(t_elem *list);
void	rrb(t_elem *list);
void	rrr(t_stack *stacks);

/* Algo */
void	apply_algo(t_stack *stacks);
void	algo_for_three(t_elem *list);
void	algo_for_four(t_stack *stacks);
void	algo_for_five(t_stack *stacks);
void	algo_push_swap(t_stack *stacks);

#endif
