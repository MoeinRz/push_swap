/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:41:01 by mrezaei           #+#    #+#             */
/*   Updated: 2022/10/30 14:56:24 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitem, size_t size)
{
	char	*str;
	size_t	len;

	len = nitem * size;
	str = malloc(len);
	if (!str)
		return (NULL);
	ft_bzero(str, len);
	return (str);
}
