/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_sort_big.c                                                            */
/*                                                                            */
/*   By: moeinrz <moeinrezaei330@gmail.com>                                   */
/*                                                                            */
/*   Created: 2023/01/24 15:39:55 by moeinrz                                  */
/*   Updated: 2023/03/03 18:06:41 by moeinrz                                  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//===========================================================================//
//just doing some actions                                                    //
//===========================================================================//
void	sub_check_case_02(t_stack *a, t_stack *b, int select, int display)
{
	if (select == 2)
	{
		rrb(b, display);
		rrb(b, display);
		pa(a, b, display);
	}
	if (select == 1)
	{
		rrb(b, display);
		pa(a, b, display);
	}
	if (select == 3)
	{
		rb(b, display);
		pa(a, b, display);
	}
}

//===========================================================================//
//check special case to find short way                                       //
//===========================================================================//
void	check_case(t_stack *a, t_stack *b, int pivot, int display)
{
	while (is_empty(b) != -1)
	{
		if (b->t_stack[b->top] == find_max(b))
		{
			pa(a, b, display);
			continue ;
		}
		if (b->t_stack[0] == find_max(b))
		{
			sub_check_case_02(a, b, 1, display);
			continue ;
		}
		if (b->t_stack[b->top - 1] == find_max(b))
		{
			sub_check_case_02(a, b, 3, display);
			continue ;
		}
		if (b->t_stack[1] == find_max(b))
		{
			sub_check_case_02(a, b, 2, display);
			continue ;
		}
		else
			sub_check_case_01(a, b, pivot, display);
	}
}

//===========================================================================//
//make a copy of stack                                                       //
//===========================================================================//
void	copy_stack(t_stack *a, t_stack *c)
{
	int	j;

	j = 0;
	while (j < a->size)
	{
		c->top++;
		c->t_stack[j] = a->t_stack[j];
		j++;
	}
}

//===========================================================================//
//process to check is the pivot optimal or not                               //
//===========================================================================//
int	solve_action(t_stack *c, t_stack *b, int pivot, int i)
{
	int	j;

	j = 0;
	sort_action_01(c, b, pivot, 0);
	while (j < (i - 2))
	{
		push_part_0(c, b, pivot, j);
		j = j + 2;
	}
	while (is_empty(c) != -1)
		pb(c, b, 0);
	check_case(c, b, pivot, 0);
	return (c->count + b->count);
}

//===========================================================================//
//find the optimal pivot                                                     //
//===========================================================================//
int	adaptive_pivot(t_stack *a, t_stack *b, int start, int end)
{
	t_stack	c;
	int		i;
	int		count;

	i = 5;
	while (1)
	{
		init_stack(&c, a->size);
		copy_stack(a, &c);
		count = solve_action(&c, b, (end - start) / i, i);
		if ((end - start) > 100 && (end - start) <= 500 && count <= 5500)
			break ;
		if ((end - start) <= 100 && count <= 700)
			break ;
		if (i > 100)
		{
			i = 19;
			break ;
		}
		i++;
		b->count = 0;
		free_stack(&c);
	}
	free_stack(&c);
	return (i);
}
