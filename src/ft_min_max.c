/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:55:37 by mrezaei           #+#    #+#             */
/*   Updated: 2023/02/25 12:08:50 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_min(t_stack *s)
{
	int	min;
	int	i;

	i = 0;
	min = 2147483647;
	while (i <= s->top)
	{
		if (min > s->t_stack[i])
			min = s->t_stack[i];
		i++;
	}
	return (min);
}

int	find_max(t_stack *s)
{
	int	max;
	int	i;

	i = 0;
	max = -2147483648;
	while (i <= s->top)
	{
		if (max < s->t_stack[i])
			max = s->t_stack[i];
		i++;
	}
	return (max);
}

int	max_index(t_stack *a)
{
	int	max;
	int	i;
	int	max_i;

	i = 0;
	max = -2147483648;
	while (i <= a->top)
	{
		if (max < a->t_stack[i])
		{
			max = a->t_stack[i];
			max_i = i;
		}
		i++;
	}
	return (max_i);
}
