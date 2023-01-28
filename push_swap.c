/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:26:32 by mrezaei           #+#    #+#             */
/*   Updated: 2023/01/28 15:01:24 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <push_swap.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int i = 0;
	int j = 1;
	if (argc >= 2)
	{
		while (argv[j][i])
		{
			while (argv[j][i])
			{
				printf("%c\n", argv[j][i]);
				i++;
			}
		i=0;
		j++;	
		}
	}
	return (0);
}
