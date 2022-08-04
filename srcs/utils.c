/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:45:43 by mcloarec          #+#    #+#             */
/*   Updated: 2022/08/04 15:05:47 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strjoin_space(char const *s1, char const *s2, int n)
{
	char	*str;
	size_t	total;
	size_t	i;
	size_t	j;
	size_t	k;

	total = ft_strlen(s1) + ft_strlen(s2) + 2;
	str = (char *)malloc(sizeof(char) * total);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[j++] = s1[i++];
	}
	str[j++] = 32;
	k = 0;
	while (s2[k] != '\0')
		str[j++] = s2[k++];
	str[j] = '\0';
	if (n > 2)
		free((char *)s1);
	return (str);
}

long int	ft_atoli(const char *str)
{
	int			i;
	long int	result;
	int			minus;

	i = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		if (result * minus < INT_MIN || result * minus > INT_MAX)
			return (-2147483650);
		i++;
	}
	return (result * minus);
}

void	print_list(t_elem *list)
{
	if (list == NULL)
		return ;
	while (list->prev != NULL)
		list = list->prev;
	while (list)
		list = list->next;
}

t_elem	*last_list(t_elem *list)
{
	if (!list)
		return (0);
	while (list->next)
		list = list->next;
	return (list);
}

int	list_size(t_elem *list)
{
	int	size;

	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}
