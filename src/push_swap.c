/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:26:32 by mrezaei           #+#    #+#             */
/*   Updated: 2023/02/28 15:23:45 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//===========================================================================//
//decide about selecting algorithm                                           //
//===========================================================================//
void	ft_sort(t_stack *a, t_stack *b)
{
	int	size;

	size = a->top + 1;
	if (size == 2)
		sa(a, 1);
	else if (size == 3)
		sort_3digit(a);
	else if (size == 4)
		sort_4digit(a, b);
	else if (size == 5)
		sort_5digit(a, b);
	else
	{
		ft_repleace(a);
		ft_big_sort(a, b, 0, a->size);
	}
	return ;
}

//===========================================================================//
//initializeing the inputs                                                   //
//===========================================================================//
int	ft_initialize(t_stack *a, t_stack *b, int argc, char **argv)
{
	init_stack(a, input_size(argc, argv));
	init_stack(b, input_size(argc, argv));
	manage_inputs(a, argc, argv);
	if (a->size == 1)
		return (1);
	if (is_repeated(a))
	{
		ft_error(a, b, 1);
		return (1);
	}
	if (is_sorted(a))
	{
		ft_error(a, b, 0);
		return (1);
	}
	return (0);
}

//===========================================================================//
//main file                                                                  //
//===========================================================================//
int	main(int argc, char **argv)
{
	t_stack	a;	
	t_stack	b;

	if (argc == 1)
		return (1);
	if (input_size(argc, argv) == 1)
		return (1);
	if (ft_initialize(&a, &b, argc, argv) == 1)
		return (1);
	ft_sort(&a, &b);
	if (a.t_stack)
		free_stack(&a);
	if (b.t_stack)
		free_stack(&b);
	return (0);
}
