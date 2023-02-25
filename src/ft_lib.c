/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:42:19 by mrezaei           #+#    #+#             */
/*   Updated: 2023/02/25 15:02:45 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_isdigit(int a)
{
	if (a <= '9' && a >= '0')
	{
		return (a);
	}
	else
		return (0);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || \
	c == '\f' || c == '\r');
}

int	is_number(char *str)
{
	while (*str && ft_isspace(*str))
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	if (!*str)
	{
		return (0);
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

void	ft_error(t_stack *a, t_stack *b, int print)
{
	if (print)
		write(1, "Error\n", 6);
	if (a->t_stack)
		free_stack(a);
	if (b->t_stack)
		free_stack(b);
	return ;
}

int	ft_strncmp(const char *dest, const char *src, size_t len)
{
	size_t	j;

	j = 0;
	if (!len)
		return (0);
	while (dest[j] == src[j] && src[j] && j < len - 1)
		++j;
	return ((unsigned char)dest[j] - (unsigned char)src[j]);
}
