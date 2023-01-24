/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:01:25 by mrezaei           #+#    #+#             */
/*   Updated: 2022/11/06 19:03:14 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//===========================================================================//
//Counting Number of the Words                                               //
//===========================================================================//
static size_t	ft_nb_w(char const *s, char c)
{
	size_t	i;
	size_t	nb_words;

	if (!s[0])
		return (0);
	i = 0;
	nb_words = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_words++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_words++;
	return (nb_words);
}

//===========================================================================//
//Finding the Next Word                                                      //
//===========================================================================//
static void	ft_next_word(char **next_w, size_t *next_w_len, char c)
{
	size_t	i;

	*next_w += *next_w_len;
	*next_w_len = 0;
	i = 0;
	while (**next_w && **next_w == c)
		(*next_w)++;
	while ((*next_w)[i])
	{
		if ((*next_w)[i] == c)
			return ;
		(*next_w_len)++;
		i++;
	}
}

//===========================================================================//
//Malloc Error                                                               //
//===========================================================================//
static char	**ft_malloc_error(char **str1)
{
	size_t	i;

	i = 0;
	while (str1[i])
	{
		free(str1[i]);
		i++;
	}
	free(str1);
	return (NULL);
}

//===========================================================================//
//split                                                                      //
//===========================================================================//
char	**ft_split(char const *s, char c)
{
	char	**str1;
	char	*next_w;
	size_t	next_w_len;
	size_t	i;

	if (!s)
		return (NULL);
	str1 = (char **)malloc(sizeof(char *) * (ft_nb_w(s, c) + 1));
	if (!str1)
		return (NULL);
	i = 0;
	next_w = (char *)s;
	next_w_len = 0;
	while (i < ft_nb_w(s, c))
	{
		ft_next_word(&next_w, &next_w_len, c);
		str1[i] = (char *)malloc(sizeof(char) * (next_w_len + 1));
		if (!str1[i])
			return (ft_malloc_error(str1));
		ft_strlcpy(str1[i], next_w, next_w_len + 1);
		i++;
	}
	str1[i] = NULL;
	return (str1);
}
