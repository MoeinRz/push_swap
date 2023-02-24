
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:18:59 by mrezaei           #+#    #+#             */
/*   Updated: 2023/02/24 17:48:09 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "get_next_line.h"

// size_t	ft_strlen(char const *str)
// {
// 	unsigned int	len;

// 	len = 0;
// 	while (str[len])
// 		len++;
// 	return (len);
// }

size_t	ft_strlcpy(char *dest, char *src, size_t len)
{
	unsigned int	i;
	size_t			s;

	s = ft_strlen(src);
	i = 0;
	if (len != 0)
	{
		while (src[i] != '\0' && i < len - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (s);
}
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


typedef struct s_stack{
	int	*t_stack;
	int	top;
	int	size;
}	t_stack;

void	init_stack(t_stack *s, int size)
{
	s->t_stack = (int *)malloc(size * sizeof(int));
	s->top = -1;
	s->size = size;
}

void	free_stack(t_stack *s)
{
	free(s->t_stack);
	s->t_stack = NULL;
	s->top = -1;
	s->size = 0;
}

int	is_empty(t_stack *s)
{
	if (s->top == -1)
		return (-1);
	else
		return (s->top);
}

int	is_full(t_stack *s)
{
	return (s->top == s->size - 1);
}

void	ptest(t_stack *s)
{
	int	i;

	if (s == NULL)
	{
		printf("Error: t_stack is null\n");
		return ;
	}
	i = s->top;
	if (is_empty(s) == -1)
	{
		printf("t_stack is empty\n");
		return ;
	}
	while (i >= 0)
	{
		printf("%d ", s->t_stack[i]);
		i--;
	}
	printf("\n");
}

int	pop(t_stack *s)
{
	int	tmp;

	tmp = 0;
	if (is_empty(s) == -1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	tmp = s->t_stack[s->top];
	s->top--;
	return (tmp);
}

void	push(t_stack *s, int item)
{
	int	i;

	if (is_full(s))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	i = s->top;
	while (i >= 0)
	{
		s->t_stack[i + 1] = s->t_stack[i];
		i--;
	}
	s->t_stack[0] = item;
	s->top++;
}

void	push_end(t_stack *s, int item)
{
	if (is_full(s))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	s->top++;
	s->t_stack[s->top] = item;
}

void	sa(t_stack *a)
{
	int	temp;

	if (a->top < 1)
		return ;
	temp = a->t_stack[a->top];
	a->t_stack[a->top] = a->t_stack[a->top - 1];
	a->t_stack[a->top - 1] = temp;
	printf("sa\n");
}

void	sb(t_stack *b)
{
	int	temp;

	if (b->top < 1)
		return ;
	temp = b->t_stack[b->top];
	b->t_stack[b->top] = b->t_stack[b->top - 1];
	b->t_stack[b->top - 1] = temp;
	printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	printf("ss\n");
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->top == -1)
		return ;
	push_end(a, pop(b));
	printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	int	temp;

	temp = 0;
	if (a->top == -1)
		return ;
	push_end(b, pop(a));
	printf("pb\n");
}

void	ra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->top == -1)
		return ;
	temp = a->t_stack[a->top];
	i = a->top;
	while (i > 0)
	{
		a->t_stack[i] = a->t_stack[i - 1];
		i--;
	}
	a->t_stack[0] = temp;
	printf("ra\n");
}

void	rb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->top == -1)
		return ;
	temp = b->t_stack[b->top];
	i = b->top;
	while (i > 0)
	{
		b->t_stack[i] = b->t_stack[i - 1];
		i--;
	}
	b->t_stack[0] = temp;
	printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	printf("rr\n");
}

void	rra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->top == -1)
		return ;
	temp = a->t_stack[0];
	i = 0;
	while (i < a->top)
	{
		a->t_stack[i] = a->t_stack[i + 1];
		i++;
	}
	a->t_stack[a->top] = temp;
	printf("rra\n");
}

void	rrb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->top == -1)
		return ;
	temp = b->t_stack[0];
	i = 0;
	while (i < b->top)
	{
		b->t_stack[i] = b->t_stack[i + 1];
		i++;
	}
	b->t_stack[b->top] = temp;
	printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	printf("rrr\n");
}

int	is_sorted(t_stack *a)
{
	int	i;

	if (a->top == -1)
		return (0);
	i = 0;
	while (i < a->top)
	{
		if (a->t_stack[i] < a->t_stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_isdigit(int a)
{
	if (a <= '9' && a >= '0')
	{
		return (a);
	}
	else
		return (0);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || \
	c == '\f' || c == '\r');
}

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

int	is_repeated(t_stack *s)
{
	int	i;
	int	j;

	i = 0;
	while (i <= s->top)
	{
		j = i + 1;
		while (j <= s->top)
		{
			if (s->t_stack[i] == s->t_stack[j])
				return (1);
		j++;
		}
	i++;
	}
	return (0);
}

int	count_digits(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			i++;
			continue ;
		}
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		count++;
		while (ft_isdigit(str[i]))
			i++;
	}
	return (count);
}

int	input_size(int argc, char **argv)
{
	int	count;
	int	i;

	i = 1;
	count = 0;
	while (i < argc)
	{
		count += count_digits(argv[i]);
		i++;
	}
	return (count);
}

int	extract_number(char **str)
{
	int	sign;
	int	num;

	sign = 1;
	if (**str == '+')
		(*str)++;
	else if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	num = 0;
	while (ft_isdigit(**str))
	{
		num = num * 10 + (**str - '0');
		(*str)++;
	}
	return (num * sign);
}

void	process_input(t_stack *a, char *str)
{
	int	num;

	while (*str != '\0')
	{
		while (*str == ' ' || *str == '\t')
			str++;
		if (*str == '\0')
			break ;
		num = extract_number(&str);
		push(a, num);
	}
}

void	manage_inputs(t_stack *a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		process_input(a, argv[i]);
		i++;
	}
}

void	ft_error(t_stack *a, t_stack *b, int print)
{
	if (print)
		write(1, "Error\n", 6);
	free_stack(a);
	free_stack(b);
	return ;
}

int	ft_initialize(t_stack *a, t_stack *b, int argc, char **argv)
{
	init_stack(a, input_size(2, argv));
	init_stack(b, input_size(2, argv));
	manage_inputs(a, 2, argv);
	if (is_sorted(a))
	{
		ft_error(a, b, 0);
		return (0);
	}
	if (is_repeated(a))
	{
		ft_error(a, b, 1);
		return (0);
	}
	return (1);
}

int	do_operating(t_stack *a, t_stack *b, char *op)
{		printf("inja=%s", op);
	if (strcmp(op, "sa") == 0){
		sa(a);
		printf("oooonja");
		}
	else if (strcmp(op, "sb") == 0)
		sb(b);
	else if (strcmp(op, "ss") == 0)
		ss(a, b);
	else if (strcmp(op, "ra") == 0)
		ra(a);
	else if (strcmp(op, "rra") == 0)
		rra(a);
	else if (strcmp(op, "rb") == 0)
		rb(b);
	else if (strcmp(op, "rrb") == 0)
		rrb(b);
	else if (strcmp(op, "rr") == 0)
		rr(a, b);
	else if (strcmp(op, "rrr") == 0)
		rrr(a, b);
	else if (strcmp(op, "pa") == 0)
		pa(a, b);
	else if (strcmp(op, "pb") == 0)
		pb(a, b);
	return (1);
}

// int	main(int argc, char **argv)
// {
// 	t_stack	a;	
// 	t_stack	b;
// 	char	**split;
// 	char	**op;
// 	int		i;

// 	i = 0;
// 	char *my_argv[] = {"program_name", "68 19 60 89", "ra pb rra sa pa"};
// 	argc = sizeof(my_argv) / sizeof(char *);
// 	argv = my_argv;
// 	if (argc != 3)
// 	{
// 		write(1, "Error\n", 6);
// 		return (0);
// 	}
// 	if (!input_size(2, argv))
// 	{
// 		ft_error(&a, &b, 1);
// 		return (0);
// 	}
// 	if (!ft_initialize(&a, &b, 2, argv))
// 		return (0);
// 	op = ft_split(argv[2], ' ');
// 	while (*op)
// 	{
// 		do_operating(&a, &b, *op);
// 		op++;
// 	}
// 	if (is_sorted(&a))
// 		write(1, "OK\n", 3);
// 	else
// 		write(1, "KO\n", 3);
// 	free_stack(&a);
// 	free_stack(&b);
// 	return (1);
// }
void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	do_operating0(t_stack *a, t_stack *b, char *op)
{
	printf("inja");
	if (strcmp(op, "sa") == 0)
	{
		sa(a);
		printf("oooonja");
	}
return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;	
	t_stack	b;
	char	**split;
	char	*line;
	int		i;
			printf("argc=%d\n", argc);
	i = 0;
	// if (argc != 3)
	// {
	// 	write(1, "Error\n", 6);
	// 	return (0);
	// }
	// if (!input_size(1, argv))
	// {
	// 	ft_error(&a, &b, 1);
	// 	return (0);
	// }
	if (!ft_initialize(&a, &b, argc, argv))
		return (0);
				ptest(&a);
			ptest(&b);
	while ((line = get_next_line(STDIN_FILENO)))
	{
		split = ft_split(line, ' ');
		i = 0;
		while (split[i])
		{
			do_operating0(&a, &b, split[i]);
			i++;
		}
		free(line);
		free_split(split);
	}
	if (is_sorted(&a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

