/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_sort_big_utils_02.c                                                   */
/*                                                                            */
/*   By: moeinrz <moeinrezaei330@gmail.com>                                   */
/*                                                                            */
/*   Created: 2023/01/24 15:39:55 by moeinrz                                  */
/*   Updated: 2023/03/03 18:06:41 by moeinrz                                  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//===========================================================================//
//push the first and second part of a to b                                   //
//===========================================================================//
void	sort_action_01(t_stack *a, t_stack *b, int pivot, int display)
{
	int	i;
	int	top;
	int	count;

	top = a->top;
	count = 0;
	i = -1;
	while (++i <= top)
	{
		if (a->t_stack[a->top] < 1 * pivot)
		{
			pb(a, b, display);
			continue ;
		}
		if (a->t_stack[a->top] >= pivot && a->t_stack[a->top] < 2 * pivot)
		{
			pb(a, b, display);
			rb(b, display);
			continue ;
		}
		ra(a, display);
	}
}

//===========================================================================//
//push the midel parts of a to b                                             //
//===========================================================================//
void	push_part_1(t_stack *a, t_stack *b, int pivot, int j)
{
	int	i;
	int	top;

	top = a->top;
	i = -1;
	while (++i <= top)
	{
		if ((a->t_stack[a->top] >= ((j + 2) * pivot)) \
			&& (a->t_stack[a->top] < ((j + 3) * pivot)))
		{
			pb(a, b, 1);
			continue ;
		}
		if ((a->t_stack[a->top] >= ((j + 3) * pivot)) \
			&& (a->t_stack[a->top] < ((j + 4) * pivot)))
		{
			pb(a, b, 1);
			rb(b, 1);
			continue ;
		}
		ra(a, 1);
	}
}

//===========================================================================//
//push back from a to b                                                      //
//===========================================================================//
void	sort_action_03(t_stack *a, t_stack *b, int pivot, int display)
{
	int	max;
	int	max1;
	int	max2;

	if (b->top > pivot)
	{
		max = find_max(b);
		max1 = get_index(b, find_max(b));
		max2 = get_index(b, (find_max(b) - 1));
		if ((max1 >= (b->top / 2) && max2 >= (b->top / 2)) \
			|| (max1 < (b->top / 2) && max2 < (b->top / 2)))
			pushback_same_side(a, b, max1, display);
		else
			pushback_dif_side_0(a, b, pivot, display);
	}
	else
	{
		max1 = max_index(b);
		if (abs(max1 - b->top) <= pivot / 2)
			rb(b, display);
		else
			rrb(b, display);
	}
}

//===========================================================================//
//push back if the first and second max be in different sides                //
//===========================================================================//
void	push_part_0(t_stack *a, t_stack *b, int pivot, int j)
{
	int	i;
	int	top;

	top = a->top;
	i = -1;
	while (++i <= top)
	{
		if ((a->t_stack[a->top] >= ((j + 2) * pivot)) \
			&& (a->t_stack[a->top] < ((j + 3) * pivot)))
		{
			pb(a, b, 0);
			continue ;
		}
		if ((a->t_stack[a->top] >= ((j + 3) * pivot)) \
			&& (a->t_stack[a->top] < ((j + 4) * pivot)))
		{
			pb(a, b, 0);
			rb(b, 0);
			continue ;
		}
		ra(a, 0);
	}
}

//===========================================================================//
//trying pushback to a                                                       //
//===========================================================================//
void	sub_check_case_01(t_stack *a, t_stack *b, int pivot, int display)
{
	sort_action_03(a, b, pivot, display);
	if (!is_sorted(a))
		sa(a, display);
}
