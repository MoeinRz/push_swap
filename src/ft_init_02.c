/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moein <moein@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:52:24 by mrezaei           #+#    #+#             */
/*   Updated: 2023/02/25 23:41:39 by moein            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//===========================================================================//
//count the number of inputs                                                 //
//===========================================================================//
int	count_digits(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			i++;
			continue ;
		}
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		count++;
		while (ft_isdigit(str[i]))
			i++;
	}
	return (count);
}

//===========================================================================//
//find the size of inputs for init                                           //
//===========================================================================//
int	input_size(int argc, char **argv)
{
	int	count;
	int	i;

	i = 1;
	count = 0;
	while (i < argc)
	{
		count += count_digits(argv[i]);
		i++;
	}
	return (count);
}

//===========================================================================//
//it is atoi                                                                 //
//===========================================================================//
int	extract_number(char **str)
{
	int		sign;
	long	num;

	sign = 1;
	if (**str == '+')
		(*str)++;
	else if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	num = 0;
	while (ft_isdigit(**str))
	{
		num = num * 10 + (**str - '0');
		(*str)++;
	}
	num = num * sign;
	if (num <= 2147483647 && num >= -2147483648)
		return (num);
	write(1, "Error\n", 6);
	exit(1);
}

//===========================================================================//
//split the space in input and push the numbers to a                         //
//===========================================================================//
void	process_input(t_stack *a, char *str)
{
	int	num;

	while (*str != '\0')
	{
		while (*str == ' ' || *str == '\t')
			str++;
		if (*str == '\0')
			break ;
		num = extract_number(&str);
		push(a, num);
	}
}

//===========================================================================//
//start the processing inputs                                                //
//===========================================================================//
void	manage_inputs(t_stack *a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		process_input(a, argv[i]);
		i++;
	}
}
