/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:09:37 by mrezaei           #+#    #+#             */
/*   Updated: 2022/11/05 15:23:32 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		i;
	char	str[10];

	num = n;
	if (num == 0)
		ft_putchar_fd('0', fd);
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	i = 0;
	while (num > 0)
	{
		str[i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar_fd(str[i], fd);
		i--;
	}
}
