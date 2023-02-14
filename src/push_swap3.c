/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:03:06 by mrezaei           #+#    #+#             */
/*   Updated: 2023/02/14 15:55:30 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

typedef	struct {
	int	*stack;
	int	top;
	int	size;
} stack;

void	init_stack(stack *s, int size)
{
	s->stack = (int *)calloc(size * sizeof(int), 0);
	s->top = -1;
	s->size = size;
}

void	free_stack(stack *s)
{
	free(s->stack);
	s->stack = NULL;
	s->top = -1;
	s->size = 0;
}

int	is_empty(stack *s)
{
	return (s->top == -1);
}

int	is_full(stack *s)
{
	return (s->top == s->size - 1);
}

int	pop(stack *s)
{
	if (is_empty(s))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	return (s->stack[s->top--]);
//	return (s->stack[s->size - 1 - (s->top--)]);
}

void	push(stack *s, int item)
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
		s->stack[i + 1] = s->stack[i];
		i--;
	}
	s->stack[0] = item;
	s->top++;
}

void	push_end(stack *s, int item)
{
	if (is_full(s))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	// Add the new element to the end of the stack
	s->stack[++(s->top)] = item;
}

void	ptest(stack *s)
{
	if (s == NULL)
	{
		printf("Error: Stack is null\n");
		return ;
	}
	if (is_empty(s))
	{
		printf("Stack is empty\n");
		return ;
	}
	// printf("Stack elements from top to bottom: ");
	for (int i = s->top; i >= 0; i--)
	{
		printf("%d ", s->stack[i]);
	}
	printf("\n");
}

void	sa(stack *a)
{
	int	temp;

	if (a->top < 1)
		return ;
	temp = a->stack[a->top];
	a->stack[a->top] = a->stack[a->top - 1];
	a->stack[a->top - 1] = temp;
	printf("sa\n");
}

void	sb(stack *b)
{
	int	temp;

	if (b->top < 1)
		return ;
	temp = b->stack[b->top];
	b->stack[b->top] = b->stack[b->top - 1];
	b->stack[b->top - 1] = temp;
	printf("sb\n");
}

void	ss(stack *a, stack *b)
{
	sa(a);
	sb(b);
	printf("ss\n");
}

void	pa(stack *a, stack *b)
{
	if (b->top == -1)
		return;
	int temp = b->stack[b->top];  // remove the top element from b and store it in temp
	b->top--;
	push_end(a, temp);      // add temp to the top of a
	printf("pa\n");
}

void	pb(stack *a, stack *b)
{
	if (a->top == -1)
		return;
	int temp = pop(a);  // remove the top element from a and store it in temp
	push_end(b, temp);  // add temp to the bottom of b
	printf("pb\n");
}

void	ra(stack *a)
{
	int	temp;
	int	i;

	if (a->top == -1)
		return;
	temp = a->stack[a->top];
	i = a->top;
	while (i > 0)
	{
		a->stack[i] = a->stack[i - 1];
		i--;
	}
	a->stack[0] = temp;
	printf("ra\n");
}

void	rb(stack *b)
{
	int	temp;
	int	i;

	if (b->top == -1)
		return;
	temp = b->stack[b->top];
	i = b->top;
	while (i > 0)
	{
		b->stack[i] = b->stack[i - 1];
		i--;
	}
	b->stack[0] = temp;
	printf("rb\n");
}

void	rr(stack *a, stack *b)
{
	ra(a);
	rb(b);
	printf("rr\n");
}

void	rra(stack *a)
{
	int	temp;
	int	i;

	if (a->top == -1)
		return ;
	temp = a->stack[0];
	i = 0;
	while (i < a->top)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
	a->stack[a->top] = temp;
	printf("rra\n");
}

void	rrb(stack *b)
{
	int	temp;
	int	i;

	if (b->top == -1)
		return ;
	temp = b->stack[0];
	i = 0;
	while (i < b->top)
	{
		b->stack[i] = b->stack[i + 1];
		i++;
	}
	b->stack[b->top] = temp;
	printf("rrb\n");
}

void	rrr(stack *a, stack *b)
{
	rra(a);
	rrb(b);
	printf("rrr\n");
}

int	check_sorted(stack *a)
{
	int	i;

	if (a->top == -1)
		return (0);
	i = 0;
	while (i < a->top)
	{
		if (a->stack[i] < a->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int is_number(char *str)
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
int is_repeated(stack *s) {
    for (int i = 0; i <= s->top; i++) {
        for (int j = i + 1; j <= s->top; j++) {
            if (s->stack[i] == s->stack[j]) {
                return 1; // found a duplicate
            }
        }
    }
    return 0; // no duplicates found
}

int	is_repeated2(stack *a, stack *b)
{
	int	i;

	i = 0;
	while (i <= a->top)
	{
		while (!is_empty(b) && b->stack[b->top] > a->stack[i])
			pop(b);
		if (!is_empty(b) && b->stack[b->top] == a->stack[i])
			return (1);
		push(b, a->stack[i]);
		i++;
	}
	return (1);
}

void	ft_mid_sort(stack *stack_a)
{
	int	v[3];
	int	temp;
	int	i;
	int	j;

	v[0] = stack_a->stack[0];
	v[1] = stack_a->stack[1];
	v[2] = stack_a->stack[2];
	if ((v[2] > v[1]) && (v[2] > v[0]) && (v[1] > v[0]))
	{
		sa(stack_a);
		rra(stack_a);
		return ;
	}
	else if ((v[0] < v[1]) && (v[1] > v[2]) && (v[2] < v[0]))
	{
		rra(stack_a);
		sa(stack_a);
		return ;
	}
	else if ((v[0] < v[1]) && (v[1] > v[2]) && (v[0] < v[2]))
	{
		rra(stack_a);
		return ;
	}
	else if ((v[1] < v[2]) && (v[1] < v[0]) && (v[0] < v[2]))
	{
		ra(stack_a);
		return ;
	}
	else if ((v[1] < v[2]) && (v[1] < v[0]) && (v[0] > v[2]))
	{
		sa(stack_a);
		return ;
	}
}
int find_median(stack *a) {
	int size = a->top + 1;
	int b[size];

	for (int i = 0; i < size; i++) {
		b[i] = pop(a);
	}
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (b[j] > b[i]) {  // Change comparison operator to >
				int temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
	int median;
	if (size % 2 == 0) {
		median = (b[size/2 - 1] + b[size/2]) / 2;
	} else {
		median = b[size/2];
	}
	for (int i = size - 1; i >= 0; i--) {
		push(a, b[i]);
	}

	return median;
}

void	sort_stack(stack *a, stack *b)
{
	int	size;
	int	temp;
	int	i;
	int	j;
	int	median;

	size = a->top + 1;
	i = 0;
	if (size == 2)
	{
		sa(a);
		return ;
	}
	else if (size == 3)
	{
		ft_mid_sort(a);
		return ;
	}
	else
	{
	median = find_median(a);
		while (a->top >= 0 && !check_sorted(a))
		{
			if (a->stack[a->top] <= median)
				pb(a, b);
			else
				ra(a);
		}
		while (b->top >= 0)
			pa(a, b);
		return ;

	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (a->stack[j] < a->stack[i])
			{
				temp = a->stack[i];
				a->stack[i] = a->stack[j];
				a->stack[j] = temp;
				printf("Swapped %d and %d\n", a->stack[i], a->stack[j]);
			}
			j++;
		}
		i++;
	}
	printf("Sorted stack: ");
	i = 0;
	while (i < size)
	{
		printf("%d ", a->stack[i]);
		i++;
	}
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	stack	a;
	stack	b;
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
	if (check_sorted(&a) == 1)
		return (0);
	if (is_repeated(&a) == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ptest(&a);
	sort_stack(&a, &b);
	ptest(&a);
	
	free_stack(&a);
	free_stack(&b);
	return (0);
}
