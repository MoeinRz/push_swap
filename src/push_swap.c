/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:26:32 by mrezaei           #+#    #+#             */
/*   Updated: 2023/02/07 19:00:36 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <push_swap.h>
#include <unistd.h>

#define MAX_INT_LENGTH 11

void	error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	get_number_from_string(const char *str, int *number)
{
	int	sign;
	int	i;
	int	value;

	sign = 1;
	i = 0;
	value = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			value = value * 10 + str[i] - '0';
		else
			return (0);
		i++;
	}
	*number = sign * value;
	return (1);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	*stack_a;
	int	count;

	i = 1;
	count = argc - 1;
	if (argc == 1)
		return (0);
	stack_a = malloc(count * sizeof(int));
	if (!stack_a)
		error_and_exit();
	while (i < argc)
	{
		if (!get_number_from_string(argv[i], &stack_a[i - 1]))
			error_and_exit();
		i++;
	}
	free(stack_a);
	return (0);
}
