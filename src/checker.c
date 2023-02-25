/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moein <moein@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:18:59 by mrezaei           #+#    #+#             */
/*   Updated: 2023/02/26 00:32:15 by moein            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//===========================================================================//
//initializing for inputs                                                    //
//===========================================================================//
int	ft_initialize_ch(t_stack *a, t_stack *b, int argc, char **argv)
{
	init_stack(a, input_size(argc, argv));
	init_stack(b, input_size(argc, argv));
	manage_inputs(a, argc, argv);
	// if (is_sorted(a))
	// {
	// 	ft_error(a, b, 0);
	// 	return (1);
	// }
	if (is_repeated(a))
	{
		ft_error(a, b, 1);
		return (1);
	}
	return (0);
}

//===========================================================================//
//operating                                                                  //
//===========================================================================//
int	do_operating(t_stack *a, t_stack *b, char *op)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		sa(a, 0);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		sb(b, 0);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ss(a, b, 0);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		ra(a, 0);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		rra(a, 0);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rb(b, 0);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		rrb(b, 0);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		rr(a, b, 0);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		rrr(a, b, 0);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		pa(a, b, 0);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		pb(a, b, 0);
	else
		return (1);
	return (0);
}

//===========================================================================//
//receive the input and processing them                                      //
//===========================================================================//
int	process_input_ch(t_stack *a, t_stack *b)
{
	char	**split;
	char	*line;
	int		i;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		split = ft_split(line, ' ');
		i = -1;
		while (split[++i])
			if (do_operating(a, b, split[i]) == 1)
				return (1);
		free(line);
		free_split(split);
		line = get_next_line(STDIN_FILENO);
	}
	return (0);
}

//===========================================================================//
//main                                                                       //
//===========================================================================//
int	main(int argc, char **argv)
{
	t_stack	a;	
	t_stack	b;

	if (argc < 2 || !input_size(2, argv))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (ft_initialize_ch(&a, &b, argc, argv) == 1)
		return (1);
	if (process_input_ch(&a, &b) == 1)
	{
		ft_error(&a, &b, 1);
		return (1);
	}
	if (is_sorted(&a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_error(&a, &b, 0);
	return (0);
}
