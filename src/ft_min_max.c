/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_min_max.c                                                             */
/*                                                                            */
/*   By: moeinrz <moeinrezaei330@gmail.com>                                   */
/*                                                                            */
/*   Created: 2023/01/24 15:39:55 by moeinrz                                  */
/*   Updated: 2023/03/03 14:48:48 by moeinrz                                  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//===========================================================================//
//find the minimum member                                                    //
//===========================================================================//
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

//===========================================================================//
//find the maximum member                                                    //
//===========================================================================//
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

//===========================================================================//
//find the maximum member with its index                                     //
//===========================================================================//
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
