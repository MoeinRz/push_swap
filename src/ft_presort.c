/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_presort.c                                                             */
/*                                                                            */
/*   By: moeinrz <moeinrezaei330@gmail.com>                                   */
/*                                                                            */
/*   Created: 2023/01/24 15:39:55 by moeinrz                                  */
/*   Updated: 2023/02/25 18:45:00 by moeinrz                                  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//===========================================================================//
//presorting to find indexing of each members                                //
//===========================================================================//
void	ft_presort(t_stack *a, int	*sorted)
{
	int	i;
	int	j;
	int	size;
	int	tmp;

	size = a->size;
	i = -1;
	while (++i < size)
		sorted[i] = a->t_stack[i];
	i = -1;
	while (++i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (sorted[i] > sorted[j])
			{
				tmp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = tmp;
			}
		j++;
		}
	}
}

//===========================================================================//
//replace the members with its indexing                                      //
//===========================================================================//
void	ft_repleace(t_stack *a)
{
	int	size;
	int	*sorted;
	int	i;
	int	j;

	size = a->size;
	sorted = malloc((size + 1) * sizeof(int));
	if (!sorted)
		return ;
	ft_presort(a, sorted);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (a->t_stack[i] == sorted[j])
			{
				a->t_stack[i] = j;
				break ;
			}
		}
	}
	free(sorted);
}
