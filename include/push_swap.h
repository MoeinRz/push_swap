/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   push_swap.h                                                              */
/*                                                                            */
/*   By: moeinrz <moeinrezaei330@gmail.com>                                   */
/*                                                                            */
/*   Created: 2023/01/24 15:39:55 by moeinrz                                  */
/*   Updated: 2023/03/03 17:45:12 by moeinrz                                  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack{
	int	*t_stack;
	int	top;
	int	size;
	int	count;
}	t_stack;

size_t	ft_strlen(char *str);
char	*ft_strchr(const char *str, int c);
void	ft_bzero(void *str, size_t len);
void	*ft_calloc(size_t nitem, size_t size);
char	*ft_strjoin(char *s1, char *s2);
void	init_stack(t_stack *s, int size);
void	free_stack(t_stack *s);
int		is_empty(t_stack *s);
int		is_full(t_stack *s);
int		pop(t_stack *s);
void	push(t_stack *s, int item);
void	push_end(t_stack *s, int item);
void	sa(t_stack *a, int display);
void	sb(t_stack *b, int display);
void	pa(t_stack *a, t_stack *b, int display);
void	pb(t_stack *a, t_stack *b, int display);
void	ss(t_stack *a, t_stack *b, int display);
void	ra(t_stack *a, int display);
void	rb(t_stack *b, int display);
void	rr(t_stack *a, t_stack *b, int display);
void	rra(t_stack *a, int display);
void	rrb(t_stack *b, int display);
void	rrr(t_stack *a, t_stack *b, int display);
size_t	ft_strlcpy(char *dest, char *src, size_t len);
int		is_sorted(t_stack *a);
int		ft_isdigit(int a);
int		ft_isspace(char c);
int		is_number(char *str);
int		is_repeated(t_stack *s);
int		find_min(t_stack *s);
int		find_max(t_stack *s);
void	sort_3digit(t_stack *a);
void	ft_action_01(t_stack *a, t_stack *b);
void	ft_action_02(t_stack *a, t_stack *b);
void	sort_4digit(t_stack *a, t_stack *b);
void	sort_4digit(t_stack *a, t_stack *b);
void	ft_action_03(t_stack *a, t_stack *b);
void	ft_action_04(t_stack *a, t_stack *b);
void	ft_action_05(t_stack *a, t_stack *b);
void	ft_action_06(t_stack *a, t_stack *b);
void	ft_action_07(t_stack *a, t_stack *b);
void	ft_action_08(t_stack *a, t_stack *b);
void	ft_action_09(t_stack *a, t_stack *b);
void	sort_5digit(t_stack *a, t_stack *b);
void	ft_presort(t_stack *a, int	*sorted);
void	ft_repleace(t_stack *a);
int		max_index(t_stack *a);
void	sort_action_01(t_stack *a, t_stack *b, int pivot, int display);
void	sort_action_03(t_stack *a, t_stack *b, int pivot, int display);
void	ft_big_sort(t_stack *a, t_stack *b, int start, int end);
void	ft_big_sort_new(t_stack *a, t_stack *b, int start, int end);
int		adaptive_pivot(t_stack *a, t_stack *b, int start, int end);
int		get_index(t_stack *s, int num);
void	push_part_0(t_stack *a, t_stack *b, int pivot, int j);
void	push_part_1(t_stack *a, t_stack *b, int pivot, int j);
void	check_case(t_stack *a, t_stack *b, int pivot, int display);
void	pushback_same_side(t_stack *a, t_stack *b, int max1, int display);
void	pushback_dif_side_01(t_stack *a, t_stack *b, int max, int display);
void	pushback_dif_side_02(t_stack *a, t_stack *b, int max, int display);
void	pushback_dif_side_0(t_stack *a, t_stack *b, int pivot, int display);
void	sub_check_case_01(t_stack *a, t_stack *b, int pivot, int display);
void	ft_sort(t_stack *a, t_stack *b);
int		count_digits(char *str);
int		input_size(int argc, char **argv);
int		extract_number(char **str);
void	process_input(t_stack *a, char *str);
void	manage_inputs(t_stack *a, int argc, char **argv);
void	ft_error(t_stack *a, t_stack *b, int print);
int		ft_initialize(t_stack *a, t_stack *b, int argc, char **argv);

#endif
