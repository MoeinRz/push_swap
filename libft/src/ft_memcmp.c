/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:02:47 by mrezaei           #+#    #+#             */
/*   Updated: 2022/11/01 17:41:05 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *dest, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			j;

	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	j = 0;
	while (j < len)
	{
		if (s1[j] != s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		j++;
	}
	return (0);
}
