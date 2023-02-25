/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moein <moein@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:26:32 by mrezaei           #+#    #+#             */
/*   Updated: 2023/02/25 01:44:21 by moein            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <push_swap.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// void	check_leaks(void)
// {
// 	system("leaks a.out");
// }

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

void	sa(t_stack *a, int display)
{
	int	temp;

	if (a->top < 1)
		return ;
	temp = a->t_stack[a->top];
	a->t_stack[a->top] = a->t_stack[a->top - 1];
	a->t_stack[a->top - 1] = temp;
	if (display)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int display)
{
	int	temp;

	if (b->top < 1)
		return ;
	temp = b->t_stack[b->top];
	b->t_stack[b->top] = b->t_stack[b->top - 1];
	b->t_stack[b->top - 1] = temp;
	if (display)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b, int display)
{
	sa(a, 0);
	sb(b, 0);
	if (display)
		write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b, int display)
{
	if (b->top == -1)
		return ;
	push_end(a, pop(b));
	if (display)
		write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b, int display)
{
	int	temp;

	temp = 0;
	if (a->top == -1)
		return ;
	push_end(b, pop(a));
	if (display)
		write(1, "pb\n", 3);
}

void	ra(t_stack *a, int display)
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
	if (display)
		write(1, "ra\n", 3);
}

void	rb(t_stack *b, int display)
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
	if (display)
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b, int display)
{
	ra(a, 0);
	rb(b, 0);
	if (display)
		write(1, "rr\n", 3);
}

void	rra(t_stack *a, int display)
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
	if (display)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b, int display)
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
	if (display)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b, int display)
{
	rra(a, 0);
	rrb(b, 0);
	if (display)
		write(1, "rrr\n", 4);
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

int	find_min(t_stack *s)
{
	int	min;
	int	i;

	i = 0;
	min = 2147483647;
	while (i <= s->top)
	{
		if (min > s->t_stack[i])
			min = s->t_stack[i];
		i++;
	}
	return (min);
}

int	find_max(t_stack *s)
{
	int	max;
	int	i;

	i = 0;
	max = -2147483648;
	while (i <= s->top)
	{
		if (max < s->t_stack[i])
			max = s->t_stack[i];
		i++;
	}
	return (max);
}

void	sort_3digit(t_stack *a)
{
	int	v[3];

	v[0] = a->t_stack[0];
	v[1] = a->t_stack[1];
	v[2] = a->t_stack[2];
	if ((v[2] > v[1]) && (v[2] > v[0]) && (v[1] > v[0]))
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if ((v[0] < v[1]) && (v[1] > v[2]) && (v[2] < v[0]))
	{
		rra(a, 1);
		sa(a, 1);
	}
	else if ((v[0] < v[1]) && (v[1] > v[2]) && (v[0] < v[2]))
		rra(a, 1);
	else if ((v[1] < v[2]) && (v[1] < v[0]) && (v[0] < v[2]))
		ra(a, 1);
	else if ((v[1] < v[2]) && (v[1] < v[0]) && (v[0] > v[2]))
		sa(a, 1);
	return ;
}

void	ft_action_01(t_stack *a, t_stack *b)
{
	ra(a, 1);
	ra(a, 1);
	pb(a, b, 1);
	sort_3digit(a);
	pa(a, b, 1);
}

void	ft_action_02(t_stack *a, t_stack *b)
{
	rra(a, 1);
	pb(a, b, 1);
	sort_3digit(a);
	pa(a, b, 1);
}

void	sort_4digit(t_stack *a, t_stack *b)
{
	int	v[4];
	int	min;

	min = find_min(a);
	v[0] = a->t_stack[0];
	v[1] = a->t_stack[1];
	v[2] = a->t_stack[2];
	v[3] = a->t_stack[3];
	if (v[3] == min)
	{
		pb(a, b, 1);
		sort_3digit(a);
		pa(a, b, 1);
	}
	else if (v[2] == min)
	{
		ra(a, 1);
		pb(a, b, 1);
		sort_3digit(a);
		pa(a, b, 1);
	}
	else if (v[1] == min)
		ft_action_01(a, b);
	else
		ft_action_02(a, b);
}

void	ft_action_03(t_stack *a, t_stack *b)
{
	pb(a, b, 1);
	rra(a, 1);
	pb(a, b, 1);
	sort_3digit(a);
	pa(a, b, 1);
	ra(a, 1);
	pa(a, b, 1);
}

void	ft_action_04(t_stack *a, t_stack *b)
{
	pb(a, b, 1);
	rra(a, 1);
	pb(a, b, 1);
	sort_3digit(a);
	pa(a, b, 1);
	pa(a, b, 1);
	ra(a, 1);
}

void	ft_action_05(t_stack *a, t_stack *b)
{
	rra(a, 1);
	rra(a, 1);
	pb(a, b, 1);
	sort_4digit(a, b);
	pa(a, b, 1);
}

void	ft_action_06(t_stack *a, t_stack *b)
{
	ra(a, 1);
	ra(a, 1);
	pb(a, b, 1);
	sort_4digit(a, b);
	pa(a, b, 1);
}

void	ft_action_07(t_stack *a, t_stack *b)
{
	ra(a, 1);
	pb(a, b, 1);
	sort_4digit(a, b);
	pa(a, b, 1);
}

void	ft_action_08(t_stack *a, t_stack *b)
{
	rra(a, 1);
	pb(a, b, 1);
	sort_4digit(a, b);
	pa(a, b, 1);
}

void	ft_action_09(t_stack *a, t_stack *b)
{
	pb(a, b, 1);
	sort_4digit(a, b);
	pa(a, b, 1);
}

void	sort_5digit(t_stack *a, t_stack *b)
{
	int	v[5];
	int	min;
	int	max;

	min = find_min(a);
	max = find_max(a);
	v[0] = a->t_stack[0];
	v[1] = a->t_stack[1];
	v[2] = a->t_stack[2];
	v[3] = a->t_stack[3];
	v[4] = a->t_stack[4];
	if (v[4] == min && v[0] == max)
		ft_action_03(a, b);
	else if (v[0] == min && v[4] == max)
		ft_action_04(a, b);
	else if (v[4] == min)
		ft_action_09(a, b);
	else if (v[0] == min)
		ft_action_08(a, b);
	else if (v[1] == min)
		ft_action_05(a, b);
	else if (v[2] == min)
		ft_action_06(a, b);
	else
		ft_action_07(a, b);
}

void	ft_presort(t_stack *a, int	*sorted)
{
	int	i;
	int	j;
	int	size;
	int	tmp;

	size = a->size;
	i = -1;
	while (++i < size)
	{
		sorted[i] = a->t_stack[i];
		// i++;
	}
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
		// i++;
	}
}

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
			// j++;
		}
		// i++;
	}
	free(sorted);
}

int	max_index(t_stack *a)
{
	int	max;
	int	i;
	int	max_i;

	i = 0;
	max = -2147483648;
	while (i <= a->top)
	{
		if (max < a->t_stack[i])
		{
			max = a->t_stack[i];
			max_i = i;
		}
		i++;
	}
	return (max_i);
}

void	sort_action_01(t_stack *a, t_stack *b, int pivot)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->t_stack[a->top] < pivot)
			pb(a, b, 1);
		else
			ra(a, 1);
		i++;
	}	
}

void	sort_action_02(t_stack *a, t_stack *b, int pivot)
{
	int	j;
	int	i;

	j = 1;
	while (j < (pivot - 1))
	{
		i = 0;
		while (i < (a->size - (j * pivot)))
		{
			if (a->t_stack[a->top] >= j * pivot && a->t_stack[a->top] < \
				((j + 1) * pivot))
				pb(a, b, 1);
			else
				ra(a, 1);
			i++;
		}
		j++;
	}	
}

void	sort_action_03(t_stack *a, t_stack *b, int pivot)
{
	int	max_i;

	while (is_empty(b) != -1)
	{
		max_i = max_index(b);
		if (b->top > pivot)
		{
			if (abs(max_i - b->top) < pivot)
				rb(b, 1);
			else
				rrb(b, 1);
		}
		else
		{
			if (abs(max_i - b->top) <= pivot / 2)
				rb(b, 1);
			else
				rrb(b, 1);
		}
		if (b->t_stack[b->top] == find_max(b))
			pa(a, b, 1);
	}
}

void	ft_big_sort(t_stack *a, t_stack *b, int start, int end)
{
	int	pivot;

	if ((end - start) <= 100)
		pivot = (end - start) / 5;
	else
		pivot = (end - start) / 10;
	sort_action_01(a, b, pivot);
	sort_action_02(a, b, pivot);
	while (is_empty(a) != -1)
		pb(a, b, 1);
	sort_action_03(a, b, pivot);
}

void	ft_sort(t_stack *a, t_stack *b)
{
	int	size;

	size = a->top + 1;
	if (size == 2)
		sa(a, 1);
	else if (size == 3)
		sort_3digit(a);
	else if (size == 4)
		sort_4digit(a, b);
	else if (size == 5)
		sort_5digit(a, b);
	else
	{
		ft_repleace(a);
		ft_big_sort(a, b, 0, a->size);
	}
	return ;
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
	if (a->t_stack)
		free_stack(a);
	if (b->t_stack)
	    free_stack(b);
	return ;
}

int	ft_initialize(t_stack *a, t_stack *b, int argc, char **argv)
{
	init_stack(a, input_size(argc, argv));
	init_stack(b, input_size(argc, argv));
	manage_inputs(a, argc, argv);
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

int	main(int argc, char **argv)
{
	t_stack	a;	
	t_stack	b;
	// char *my_argv[] = {"program_name", "284 584 12 -98 25 -980 56 8 120 0"};
	// argc = sizeof(my_argv) / sizeof(char *);
	// argv = my_argv;
	if (argc == 1)
		return (0);
	if (!input_size(argc, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!ft_initialize(&a, &b, argc, argv))
		return (0);
	ft_sort(&a, &b);
	if (a.t_stack)
		free_stack(&a);
	if (b.t_stack)
	    free_stack(&b);
	// check_leaks();
	return (1);
}
