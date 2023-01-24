/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:44:36 by mrezaei           #+#    #+#             */
/*   Updated: 2022/11/04 17:15:10 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*moein;

	moein = (t_list *)malloc(sizeof(t_list));
	if (!moein)
		return (NULL);
	moein->content = content;
	moein->next = NULL;
	return (moein);
}
