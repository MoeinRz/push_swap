/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_lib.c                                                                 */
/*                                                                            */
/*   By: moeinrz <moeinrezaei330@gmail.com>                                   */
/*                                                                            */
/*   Created: 2023/01/24 15:39:55 by moeinrz                                  */
/*   Updated: 2023/03/03 14:20:48 by moeinrz                                  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//===========================================================================//
//check it is digit or not                                                   //
//===========================================================================//
int	ft_isdigit(int a)
{
	if (a <= '9' && a >= '0')
	{
		return (a);
	}
	else
		return (0);
}

//===========================================================================//
//find the space or tab                                                      //
//===========================================================================//
int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || \
	c == '\f' || c == '\r');
}

//===========================================================================//
//check it is number or not and atoi it                                      //
//===========================================================================//
int	is_number(char *str)
{
	while (*str && ft_isspace(*str))
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	if (!*str)
	{
		return (0);
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

//===========================================================================//
//free and print error                                                       //
//===========================================================================//
void	ft_error(t_stack *a, t_stack *b, int print)
{
	if (print)
		write(1, "Error\n", 6);
	if (a->t_stack)
		free_stack(a);
	if (b->t_stack)
		free_stack(b);
	return ;
}

//===========================================================================//
//ft string compareing                                                       //
//===========================================================================//
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
