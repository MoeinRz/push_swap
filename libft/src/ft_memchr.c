/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:22:11 by mrezaei           #+#    #+#             */
/*   Updated: 2022/11/05 14:08:52 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	char	*ptr;
	char	sym;

	ptr = (char *)str;
	sym = (char)c;
	while (len--)
	{
		if (*ptr == sym)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
