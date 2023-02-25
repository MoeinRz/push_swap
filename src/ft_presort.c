/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:50:12 by mrezaei           #+#    #+#             */
/*   Updated: 2023/02/25 15:59:01 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_presort(t_stack *a, int	*sorted)
{
	int	i;
	int	j;
	int	size;
	int	tmp;

	size = a->size;
	i = -1;
	while (++i < size)
		sorted[i] = a->t_stack[i];
	i = -1;
	while (++i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (sorted[i] > sorted[j])
			{
				tmp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = tmp;
			}
		j++;
		}
	}
}

void	ft_repleace(t_stack *a)
{
	int	size;
	int	*sorted;
	int	i;
	int	j;

	size = a->size;
	sorted = malloc((size + 1) * sizeof(int));
	if (!sorted)
		return ;
	ft_presort(a, sorted);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (a->t_stack[i] == sorted[j])
			{
				a->t_stack[i] = j;
				break ;
			}
		}
	}
	free(sorted);
}
