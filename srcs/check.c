/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 09:55:05 by mcloarec          #+#    #+#             */
/*   Updated: 2022/07/18 16:24:48 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	nb_comp(char *s1, char *s2)
{
	int	i;
	int j;
	int	diff;

	i = 0;
	j = i;
	diff = 0;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	diff = s1[i] - s2[j];
	return (diff);
}

static int	check_duplicata(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && nb_comp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_nb(char *str)
{
	int	i;
	int	zero;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1] != '\0')
		i++;
	zero = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] == '0')
			zero++;
		i++;
	}
	if (zero > 1)
		return (1);
	if (str[i] == '\0')
		return (0);
	return (1);
}

void	check_arg(char **argv)
{
	long int	l;
	int	i;

	i = 0;
	while (argv[i])
	{
		if (*argv[i] == '\0')
			putstr_error();
		else if (check_nb(argv[i]) == 1)
		{
			free_tab(argv);
			putstr_error();
		}
		l = ft_atoli(argv[i]);
		if (l < INT_MIN || l > INT_MAX)
		{
			free_tab(argv);
			putstr_error();
		}
		i++;
	}
	if (check_duplicata(argv) == 1)
		putstr_error();
}
