/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_sort_4digit.c                                                         */
/*                                                                            */
/*   By: moeinrz <moeinrezaei330@gmail.com>                                   */
/*                                                                            */
/*   Created: 2023/01/24 15:39:55 by moeinrz                                  */
/*   Updated: 2023/02/25 18:45:00 by moeinrz                                  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//===========================================================================//
//just an action of main algorithm                                           //
//===========================================================================//
void	ft_action_01(t_stack *a, t_stack *b)
{
	ra(a, 1);
	ra(a, 1);
	pb(a, b, 1);
	sort_3digit(a);
	pa(a, b, 1);
}

//===========================================================================//
//just an action of main algorithm                                           //
//===========================================================================//
void	ft_action_02(t_stack *a, t_stack *b)
{
	rra(a, 1);
	pb(a, b, 1);
	sort_3digit(a);
	pa(a, b, 1);
}

//===========================================================================//
//just an action of main algorithm                                           //
//===========================================================================//
void	ft_action_03(t_stack *a, t_stack *b)
{
	pb(a, b, 1);
	rra(a, 1);
	pb(a, b, 1);
	sort_3digit(a);
	pa(a, b, 1);
	ra(a, 1);
	pa(a, b, 1);
}

//===========================================================================//
//just an action of main algorithm                                           //
//===========================================================================//
void	ft_action_04(t_stack *a, t_stack *b)
{
	pb(a, b, 1);
	rra(a, 1);
	pb(a, b, 1);
	sort_3digit(a);
	pa(a, b, 1);
	pa(a, b, 1);
	ra(a, 1);
}

//===========================================================================//
//sorting algorithm for four numbers of inputs                               //
//===========================================================================//
void	sort_4digit(t_stack *a, t_stack *b)
{
	int	v[4];
	int	min;

	min = find_min(a);
	v[0] = a->t_stack[0];
	v[1] = a->t_stack[1];
	v[2] = a->t_stack[2];
	v[3] = a->t_stack[3];
	if (v[3] == min)
	{
		pb(a, b, 1);
		sort_3digit(a);
		pa(a, b, 1);
	}
	else if (v[2] == min)
	{
		ra(a, 1);
		pb(a, b, 1);
		sort_3digit(a);
		pa(a, b, 1);
	}
	else if (v[1] == min)
		ft_action_01(a, b);
	else
		ft_action_02(a, b);
}
