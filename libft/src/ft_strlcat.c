/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:28:24 by mrezaei           #+#    #+#             */
/*   Updated: 2022/11/05 15:39:17 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	j;
	size_t	k;

	k = 0;
	j = 0;
	if (!dest && len == 0)
		return (0);
	while (dest[j] && j < len)
		j++;
	while ((src[k]) && ((j + k + 1) < len))
	{
		dest[j + k] = src[k];
		k++;
	}
	if (j != len)
		dest[j + k] = '\0';
	return (j + ft_strlen(src));
}
