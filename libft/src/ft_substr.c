/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:45:20 by mrezaei           #+#    #+#             */
/*   Updated: 2022/11/06 17:33:51 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str1;
	size_t	i;
	size_t	mx;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	mx = ft_strlen(s + start);
	if (mx <= len)
		len = mx;
	str1 = (char *)malloc(len + 1);
	if (!str1)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(str1 + i) = *(s + start + i);
		i++;
	}
	*(str1 + i) = '\0';
	return (str1);
}
