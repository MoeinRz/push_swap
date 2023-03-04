/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_sort_5digit.c                                                         */
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
void	ft_action_06(t_stack *a, t_stack *b)
{
	ra(a, 1);
	ra(a, 1);
	pb(a, b, 1);
	sort_4digit(a, b);
	pa(a, b, 1);
}

//===========================================================================//
//just an action of main algorithm                                           //
//===========================================================================//
void	ft_action_07(t_stack *a, t_stack *b)
{
	ra(a, 1);
	pb(a, b, 1);
	sort_4digit(a, b);
	pa(a, b, 1);
}

//===========================================================================//
//just an action of main algorithm                                           //
//===========================================================================//
void	ft_action_08(t_stack *a, t_stack *b)
{
	rra(a, 1);
	pb(a, b, 1);
	sort_4digit(a, b);
	pa(a, b, 1);
}

//===========================================================================//
//just an action of main algorithm                                           //
//===========================================================================//
void	ft_action_09(t_stack *a, t_stack *b)
{
	pb(a, b, 1);
	sort_4digit(a, b);
	pa(a, b, 1);
}

//===========================================================================//
//sorting algorithm for five numbers of inputs                               //
//===========================================================================//
void	sort_5digit(t_stack *a, t_stack *b)
{
	int	v[5];
	int	min;
	int	max;

	min = find_min(a);
	max = find_max(a);
	v[0] = a->t_stack[0];
	v[1] = a->t_stack[1];
	v[2] = a->t_stack[2];
	v[3] = a->t_stack[3];
	v[4] = a->t_stack[4];
	if (v[4] == min && v[0] == max)
		ft_action_03(a, b);
	else if (v[0] == min && v[4] == max)
		ft_action_04(a, b);
	else if (v[4] == min)
		ft_action_09(a, b);
	else if (v[0] == min)
		ft_action_08(a, b);
	else if (v[1] == min)
		ft_action_05(a, b);
	else if (v[2] == min)
		ft_action_06(a, b);
	else
		ft_action_07(a, b);
}
