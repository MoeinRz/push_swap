/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:14:42 by mrezaei           #+#    #+#             */
/*   Updated: 2022/10/30 13:39:17 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *dest, const char *src, size_t len)
{
	size_t	j;

	j = 0;
	if (!len)
		return (0);
	while (dest[j] == src[j] && src[j] && j < len - 1)
		++j;
	return ((unsigned char)dest[j] - (unsigned char)src[j]);
}
