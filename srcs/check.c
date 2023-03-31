/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 09:55:05 by mcloarec          #+#    #+#             */
/*   Updated: 2022/08/04 15:06:23 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	nb_comp(long n1, long n2)
{
	int	diff;

	diff = 0;
	diff = n1 - n2;
	return (diff);
}

int	check_duplicata(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[j])
		{
			if (j != i && nb_comp(ft_atoli(argv[i]), ft_atoli(argv[j])) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_nb(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1] != '\0')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

void	check_arg_split(char **argv)
{
	long int	l;
	int			i;

	i = 0;
	while (argv[i])
	{
		if (*argv[i] == '\0')
			putstr_error();
		else if (check_nb(argv[i]) == 1)
			putstr_error_tab(argv);
		l = ft_atoli(argv[i]);
		if (l == -2147483650)
			putstr_error_tab(argv);
		i++;
	}
	if (check_duplicata(argv) == 1)
		putstr_error_tab(argv);
}

void	check_arg(char **argv)
{
	long int	l;
	int			i;

	i = 0;
	while (argv[i])
	{
		if (*argv[i] == '\0')
			putstr_error();
		else if (check_nb(argv[i]) == 1)
			putstr_error();
		l = ft_atoli(argv[i]);
		if (l < INT_MIN || l > INT_MAX)
			putstr_error();
		i++;
	}
	if (check_duplicata(argv) == 1)
		putstr_error();
}
