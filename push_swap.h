/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:43:08 by mcloarec          #+#    #+#             */
/*   Updated: 2022/07/20 18:41:11 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stddef.h>
# include<stdio.h>
# include<stdlib.h>
# include<limits.h>
# include<string.h>
# include"libft/libft.h"

/* Structure représentant un élément de la liste */
typedef struct s_elem
{
	int				value;
	struct s_elem	*prev;
	struct s_elem	*next;
}				 t_elem;

/* Structure d'accès à la liste
typedef struct	s_dblist
{
	t_elem	*first;
	t_elem	*last;
}				t_dblist;*/

/* Structure qui contient les 2 piles */
typedef struct s_stack
{
	t_elem	*a;
	t_elem	*b;
}				t_stack;

/* Check arguments*/
void	check_arg(char **argv);

/*Free & Error*/
void	free_tab(char **tab);
void	putstr_error(void);

/*Utils*/
long int	ft_atoli(const char *str);
void	print_list(t_elem *list);

/*Remplir pile A*/
t_elem	*fill_stack_split(char *str, t_elem *list);
t_elem	*fill_stack(char **argv, t_elem *list);
t_elem	*add_elem(t_elem *list, int value);

#endif
