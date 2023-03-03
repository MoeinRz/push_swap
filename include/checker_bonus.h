/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:39:55 by mrezaei           #+#    #+#             */
/*   Updated: 2023/03/03 17:46:52 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "push_swap.h"

size_t	ft_strlen(char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *str);
char	*ft_first_line(char *str);
char	*ft_goto_next(char *str);
size_t	ft_strlcpy(char *dest, char *src, size_t len);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *dest, const char *src, size_t len);
void	free_split(char **split);
int		ft_initialize_ch(t_stack *a, t_stack *b, int argc, char **argv);

#endif
