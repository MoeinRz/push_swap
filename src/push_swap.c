/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moein <moein@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:26:32 by mrezaei           #+#    #+#             */
/*   Updated: 2023/02/16 23:40:35 by moein            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <push_swap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

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

int	is_number(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = strlen(str);
	if (len == 0)
		return (0);
	while (i < len)
	{
		if (!isdigit(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int	is_repeated(t_stack *s)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (i <= s->top)
	{
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
		sa(a);
		rra(a);
		return ;
	}
	else if ((v[0] < v[1]) && (v[1] > v[2]) && (v[2] < v[0]))
	{
		rra(a);
		sa(a);
		return ;
	}
	else if ((v[0] < v[1]) && (v[1] > v[2]) && (v[0] < v[2]))
	{
		rra(a);
		return ;
	}
	else if ((v[1] < v[2]) && (v[1] < v[0]) && (v[0] < v[2]))
	{
		ra(a);
		return ;
	}
	else if ((v[1] < v[2]) && (v[1] < v[0]) && (v[0] > v[2]))
	{
		sa(a);
		return ;
	}
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
		pb(a, b);
		sort_3digit(a);
		pa(a, b);
	}
	else if (v[2] == min)
	{
		ra(a);
		pb(a, b);
		sort_3digit(a);
		pa(a, b);
	}
	else if (v[1] == min)
	{
		ra(a);
		ra(a);
		pb(a, b);
		sort_3digit(a);
		pa(a, b);
	}
	else
	{
		rra(a);
		pb(a, b);
		sort_3digit(a);
		pa(a, b);
	}
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
	{
		pb(a, b);
		rra(a);
		pb(a, b);
		sort_3digit(a);
		pa(a, b);
		ra(a);
		pa(a, b);
	}
	else if (v[0] == min && v[4] == max)
	{
		pb(a, b);
		rra(a);
		pb(a, b);
		sort_3digit(a);
		pa(a, b);
		pa(a, b);
		ra(a);
	}
	else if (v[4] == min)
	{
		pb(a, b);
		sort_4digit(a, b);
		pa(a, b);
	}
	else if (v[0] == min)
	{
		rra(a);
		pb(a, b);
		sort_4digit(a, b);
		pa(a, b);
	}
	else if (v[1] == min)
	{
		rra(a);
		rra(a);
		pb(a, b);
		sort_4digit(a, b);
		pa(a, b);
	}
	else if (v[2] == min)
	{
		ra(a);
		ra(a);
		pb(a, b);
		sort_4digit(a, b);
		pa(a, b);
	}
	else
	{
		ra(a);
		pb(a, b);
		sort_4digit(a, b);
		pa(a, b);
	}
}

///////////////////////////////////////////////////////////
int	get_pivot(int *arr, int start, int end)
{
	int	pivot;
	int	mid;

	mid = (start + end) / 2;
	if (arr[start] >= arr[end] && arr[start] <= arr[mid])
		pivot = start;
	else if (arr[start] >= arr[mid] && arr[start] <= arr[end])
		pivot = start;
	else if (arr[end] >= arr[start] && arr[end] <= arr[mid])
		pivot = end;
	else if (arr[end] >= arr[mid] && arr[end] <= arr[start])
		pivot = end;
	else
		pivot = mid;
	return (pivot);
}

void	partitin(t_stack *a, t_stack *b, int start, int end)
{
	int	pivot_index;
	int	pivot_value;
	int	i;

	if (start >= end)
		return ;
	pivot_index = get_pivot(a->t_stack, start, end);
	pivot_value = a->t_stack[pivot_index];
	i = a->size;
	while (i)
	{
		if (a->t_stack[a->top] < pivot_value)
			pb(a, b);
		else if (a->t_stack[a->top] == pivot_value)
			pop(a);
		else if (a->t_stack[a->top] > pivot_value)
			ra(a);
		i--;
	}
	push_end(a, pivot_value);
	while (b->top >= 0)
		pa(a, b);
	partitin(a, b, start, pivot_index - 1);
	partitin(a, b, pivot_index + 1, end);
}

void	quicksort(t_stack *a, t_stack *b)
{
	int	start;

	start = 0;
	partitin(a, b, start, a->top);
	return ;
}

void	sort(t_stack *a, t_stack *b)
{
	int	size;

	size = a->top + 1;
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_3digit(a);
	else if (size == 4)
		sort_4digit(a, b);
	else if (size == 5)
		sort_5digit(a, b);
	else
		quicksort(a, b);
	return ;
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		i;
	int		num;

	if (argc == 1)
		return (0);
	init_stack(&a, argc - 1);
	init_stack(&b, argc - 1);
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		num = atoi(argv[i]);
		push(&a, num);
		i++;
	}
	if (is_sorted(&a) == 1)
		return (0);
	if (is_repeated(&a) == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	printf("a=");
	ptest(&a);
	sort(&a, &b);
	printf("a=");
	ptest(&a);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
