/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:49:06 by mrezaei           #+#    #+#             */
/*   Updated: 2023/02/25 12:08:17 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_action_01(t_stack *a, t_stack *b, int pivot)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->t_stack[a->top] < pivot)
			pb(a, b, 1);
		else
			ra(a, 1);
		i++;
	}	
}

void	sort_action_02(t_stack *a, t_stack *b, int pivot)
{
	int	j;
	int	i;

	j = 1;
	while (j < (pivot - 1))
	{
		i = 0;
		while (i < (a->size - (j * pivot)))
		{
			if (a->t_stack[a->top] >= j * pivot && a->t_stack[a->top] < \
				((j + 1) * pivot))
				pb(a, b, 1);
			else
				ra(a, 1);
			i++;
		}
		j++;
	}	
}

void	sort_action_03(t_stack *a, t_stack *b, int pivot)
{
	int	max_i;

	while (is_empty(b) != -1)
	{
		max_i = max_index(b);
		if (b->top > pivot)
		{
			if (abs(max_i - b->top) < pivot)
				rb(b, 1);
			else
				rrb(b, 1);
		}
		else
		{
			if (abs(max_i - b->top) <= pivot / 2)
				rb(b, 1);
			else
				rrb(b, 1);
		}
		if (b->t_stack[b->top] == find_max(b))
			pa(a, b, 1);
	}
}

void	ft_big_sort(t_stack *a, t_stack *b, int start, int end)
{
	int	pivot;

	if ((end - start) <= 100)
		pivot = (end - start) / 5;
	else
		pivot = (end - start) / 10;
	sort_action_01(a, b, pivot);
	sort_action_02(a, b, pivot);
	while (is_empty(a) != -1)
		pb(a, b, 1);
	sort_action_03(a, b, pivot);
}
