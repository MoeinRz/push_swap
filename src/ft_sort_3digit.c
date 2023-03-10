/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_sort_3digit.c                                                         */
/*                                                                            */
/*   By: moeinrz <moeinrezaei330@gmail.com>                                   */
/*                                                                            */
/*   Created: 2023/01/24 15:39:55 by moeinrz                                  */
/*   Updated: 2023/02/25 18:45:00 by moeinrz                                  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//===========================================================================//
//check to find if a is sorted                                               //
//===========================================================================//
int	is_sorted(t_stack *a)
{
	int	i;

	if (a->top == -1)
		return (0);
	i = 0;
	while (i < a->top)
	{
		if (a->t_stack[i] < a->t_stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

//===========================================================================//
//check to find if there is any repeated member in a                         //
//===========================================================================//
int	is_repeated(t_stack *s)
{
	int	i;
	int	j;

	i = 0;
	while (i <= s->top)
	{
		j = i + 1;
		while (j <= s->top)
		{
			if (s->t_stack[i] == s->t_stack[j])
				return (1);
		j++;
		}
	i++;
	}
	return (0);
}

//===========================================================================//
//just an action of main algorithm                                           //
//===========================================================================//
void	ft_action_05(t_stack *a, t_stack *b)
{
	rra(a, 1);
	rra(a, 1);
	pb(a, b, 1);
	sort_4digit(a, b);
	pa(a, b, 1);
}

//===========================================================================//
//sorting algorithm for three numbers of inputs                               //
//===========================================================================//
void	sort_3digit(t_stack *a)
{
	int	v[3];

	v[0] = a->t_stack[0];
	v[1] = a->t_stack[1];
	v[2] = a->t_stack[2];
	if ((v[2] > v[1]) && (v[2] > v[0]) && (v[1] > v[0]))
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if ((v[0] < v[1]) && (v[1] > v[2]) && (v[2] < v[0]))
	{
		rra(a, 1);
		sa(a, 1);
	}
	else if ((v[0] < v[1]) && (v[1] > v[2]) && (v[0] < v[2]))
		rra(a, 1);
	else if ((v[1] < v[2]) && (v[1] < v[0]) && (v[0] < v[2]))
		ra(a, 1);
	else if ((v[1] < v[2]) && (v[1] < v[0]) && (v[0] > v[2]))
		sa(a, 1);
	return ;
}
