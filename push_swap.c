/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:26:32 by mrezaei           #+#    #+#             */
/*   Updated: 2023/01/28 21:23:16 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <push_swap.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 1;
	k = 0;
	argc = 2;
	**argv = {"12, 34"};
	if (argc >= 2)
	{
		while (argv[j][i])
		{
			while (argv[j][i])
			{
				str[k] = argv[j][i];
				i++;
				k++;
			}
			i = 0;
			j++;
		}
		str[k + 1] = '\0';
	}
	printf("%s\n", str);
	return (0);
}
