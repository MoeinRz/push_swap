/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   get_next_line_utils.c                                                    */
/*                                                                            */
/*   By: moeinrz <moeinrezaei330@gmail.com>                                   */
/*                                                                            */
/*   Created: 2023/01/24 15:39:55 by moeinrz                                  */
/*   Updated: 2023/03/03 18:06:41 by moeinrz                                  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//===========================================================================//
//calculating the length of a string                                         //
//===========================================================================//
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//===========================================================================//
//searching for a character in a string                                      //
//===========================================================================//
char	*ft_strchr(const char *str, int c)
{
	char	*tmp;

	tmp = (char *)str;
	while (*tmp != c && *tmp != 0)
		tmp++;
	if (*tmp == c)
		return (tmp);
	else
		return (NULL);
}

//===========================================================================//
//assigning zero to a string                                                 //
//===========================================================================//
void	ft_bzero(void *str, size_t len)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)str;
	i = 0;
	while (i < len)
	{
		tmp[i] = '\0';
		i++;
	}
}

//===========================================================================//
//allocating memory with initializing to Zero                                //
//===========================================================================//
void	*ft_calloc(size_t nitem, size_t size)
{
	char	*str;

	str = malloc(nitem * size);
	if (!str)
		return (NULL);
	ft_bzero(str, nitem * size);
	return (str);
}

//===========================================================================//
//joining two string to each other                                           //
//===========================================================================//
char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*res;
	int		i;
	int		j;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (len + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[len] = 0;
	return (free(s1), res);
}
