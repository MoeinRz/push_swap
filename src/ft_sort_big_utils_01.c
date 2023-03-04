/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_sort_big_utils_01.c                                                   */
/*                                                                            */
/*   By: moeinrz <moeinrezaei330@gmail.com>                                   */
/*                                                                            */
/*   Created: 2023/01/24 15:39:55 by moeinrz                                  */
/*   Updated: 2023/03/03 18:06:41 by moeinrz                                  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//===========================================================================//
//push back if the first and second max be in same side                      //
//===========================================================================//
void	pushback_same_side(t_stack *a, t_stack *b, int max1, int display)
{
	int	i;
	int	max;

	max = find_max(b);
	i = 0;
	while (i < 2)
	{
		if (b->t_stack[b->top] == max || b->t_stack[b->top] == max - 1)
		{
			pa(a, b, display);
			i++;
			continue ;
		}
		if (max1 >= (b->top / 2))
			rb(b, display);
		else
			rrb(b, display);
	}
}

//===========================================================================//
//push back if the first and second max be in different sides                //
//===========================================================================//
void	pushback_dif_side_01(t_stack *a, t_stack *b, int max, int display)
{
	while (1)
	{
		if (b->t_stack[b->top] == max || b->t_stack[b->top] == max - 1)
		{
			pa(a, b, display);
			break ;
		}
		rb(b, display);
	}
	while (1)
	{
		if (b->t_stack[b->top] == max || b->t_stack[b->top] == max - 1)
		{
			pa(a, b, display);
			break ;
		}
		rrb(b, display);
	}
}

//===========================================================================//
//push back if the first and second max be in different sides                //
//===========================================================================//
void	pushback_dif_side_02(t_stack *a, t_stack *b, int max, int display)
{
	while (1)
	{
		if (b->t_stack[b->top] == max || b->t_stack[b->top] == max - 1)
		{
			pa(a, b, display);
			break ;
		}
		rrb(b, display);
	}
	while (1)
	{
		if (b->t_stack[b->top] == max || b->t_stack[b->top] == max - 1)
		{
			pa(a, b, display);
			break ;
		}
		rb(b, display);
	}
}

//===========================================================================//
//push back if the first and second max be in different sides                //
//===========================================================================//
void	pushback_dif_side_0(t_stack *a, t_stack *b, int pivot, int display)
{
	int	max;
	int	max1;
	int	max2;

	max = find_max(b);
	max1 = get_index(b, find_max(b));
	max2 = get_index(b, (find_max(b) - 1));
	if (abs((pivot / 2) - max1) > abs((pivot / 2) - max2))
	{
		if (max1 >= (pivot / 2))
			pushback_dif_side_01(a, b, max, display);
		else
			pushback_dif_side_02(a, b, max, display);
	}
	else
	{
		if (max2 >= (pivot / 2))
			pushback_dif_side_01(a, b, max, display);
		else
			pushback_dif_side_02(a, b, max, display);
	}
}

//===========================================================================//
//find the index of member num                                               //
//===========================================================================//
int	get_index(t_stack *s, int num)
{
	int	i;

	i = 0;
	while (i <= s->top)
	{
		if (s->t_stack[i] == num)
		{
			return (i);
		}
	i++;
	}
	return (-1);
}

