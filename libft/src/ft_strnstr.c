/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:11:03 by mrezaei           #+#    #+#             */
/*   Updated: 2022/11/05 16:13:09 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (!str1 && len == 0)
		return (0);
	if (*str2 == '\0')
		return ((char *)str1);
	while (str1[i] && i < len)
	{
		j = 0;
		while (((i + j) < len) && str1[i + j] == str2[j])
		{
			if (str2[j + 1] == '\0')
				return (&((char *)str1)[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
