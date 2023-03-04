/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   push_swap.c                                                              */
/*                                                                            */
/*   By: moeinrz <moeinrezaei330@gmail.com>                                   */
/*                                                                            */
/*   Created: 2023/01/24 15:39:55 by moeinrz                                  */
/*   Updated: 2023/03/03 20:01:55 by moeinrz                                  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//===========================================================================//
//the algorithm for the big number of inputs                                 //
//===========================================================================//
void	ft_big_sort(t_stack *a, t_stack *b, int start, int end)
{
	int		pivot;
	int		i;
	int		j;

	if ((end - start) > 500)
		i = 19;
	else if ((end - start) < 100)
		i = 5;
	else
		i = adaptive_pivot(a, b, start, end);
	pivot = (end - start) / i;
	sort_action_01(a, b, pivot, 1);
	j = 0;
	while (j < (i - 2))
	{
		push_part_1(a, b, pivot, j);
		j = j + 2;
	}
	while (is_empty(a) != -1)
		pb(a, b, 1);
	check_case(a, b, pivot, 1);
}

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
	// system("leaks push_swap");
	return (0);
}
