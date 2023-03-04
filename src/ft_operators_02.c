/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_operators_02.c                                                        */
/*                                                                            */
/*   By: moeinrz <moeinrezaei330@gmail.com>                                   */
/*                                                                            */
/*   Created: 2023/01/24 15:39:55 by moeinrz                                  */
/*   Updated: 2023/03/03 12:58:48 by moeinrz                                  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//===========================================================================//
//ra                                                                         //
//===========================================================================//
void	ra(t_stack *a, int display)
{
	int	temp;
	int	i;

	if (a->top == -1)
		return ;
	temp = a->t_stack[a->top];
	i = a->top;
	while (i > 0)
	{
		a->t_stack[i] = a->t_stack[i - 1];
		i--;
	}
	a->t_stack[0] = temp;
	a->count++;
	if (display)
		write(1, "ra\n", 3);
}

//===========================================================================//
//rb                                                                         //
//===========================================================================//
void	rb(t_stack *b, int display)
{
	int	temp;
	int	i;

	if (b->top == -1)
		return ;
	temp = b->t_stack[b->top];
	i = b->top;
	while (i > 0)
	{
		b->t_stack[i] = b->t_stack[i - 1];
		i--;
	}
	b->t_stack[0] = temp;
	b->count++;
	if (display)
		write(1, "rb\n", 3);
}

//===========================================================================//
//rr                                                                         //
//===========================================================================//
void	rr(t_stack *a, t_stack *b, int display)
{
	ra(a, 0);
	rb(b, 0);
	b->count--;
	if (display)
		write(1, "rr\n", 3);
}

//===========================================================================//
//rrb                                                                        //
//===========================================================================//
void	rra(t_stack *a, int display)
{
	int	temp;
	int	i;

	if (a->top == -1)
		return ;
	temp = a->t_stack[0];
	i = 0;
	while (i < a->top)
	{
		a->t_stack[i] = a->t_stack[i + 1];
		i++;
	}
	a->t_stack[a->top] = temp;
	a->count++;
	if (display)
		write(1, "rra\n", 4);
}

//===========================================================================//
//rrb                                                                        //
//===========================================================================//
void	rrb(t_stack *b, int display)
{
	int	temp;
	int	i;

	if (b->top == -1)
		return ;
	temp = b->t_stack[0];
	i = 0;
	while (i < b->top)
	{
		b->t_stack[i] = b->t_stack[i + 1];
		i++;
	}
	b->t_stack[b->top] = temp;
	b->count++;
	if (display)
		write(1, "rrb\n", 4);
}
