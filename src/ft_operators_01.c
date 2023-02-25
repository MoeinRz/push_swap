/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operators_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:39:46 by mrezaei           #+#    #+#             */
/*   Updated: 2023/02/25 18:47:41 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//===========================================================================//
//sa                                                                         //
//===========================================================================//
void	sa(t_stack *a, int display)
{
	int	temp;

	if (a->top < 1)
		return ;
	temp = a->t_stack[a->top];
	a->t_stack[a->top] = a->t_stack[a->top - 1];
	a->t_stack[a->top - 1] = temp;
	if (display)
		write(1, "sa\n", 3);
}

//===========================================================================//
//sb                                                                         //
//===========================================================================//
void	sb(t_stack *b, int display)
{
	int	temp;

	if (b->top < 1)
		return ;
	temp = b->t_stack[b->top];
	b->t_stack[b->top] = b->t_stack[b->top - 1];
	b->t_stack[b->top - 1] = temp;
	if (display)
		write(1, "sb\n", 3);
}

//===========================================================================//
//ss                                                                         //
//===========================================================================//
void	ss(t_stack *a, t_stack *b, int display)
{
	sa(a, 0);
	sb(b, 0);
	if (display)
		write(1, "ss\n", 3);
}

//===========================================================================//
//pa                                                                         //
//===========================================================================//
void	pa(t_stack *a, t_stack *b, int display)
{
	if (b->top == -1)
		return ;
	push_end(a, pop(b));
	if (display)
		write(1, "pa\n", 3);
}

//===========================================================================//
//pb                                                                         //
//===========================================================================//
void	pb(t_stack *a, t_stack *b, int display)
{
	int	temp;

	temp = 0;
	if (a->top == -1)
		return ;
	push_end(b, pop(a));
	if (display)
		write(1, "pb\n", 3);
}
