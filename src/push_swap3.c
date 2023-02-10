/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:03:06 by mrezaei           #+#    #+#             */
/*   Updated: 2023/02/10 15:04:29 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	int *stack;
	int top;
	int size;
} stack;

void	init_stack(stack *s, int size)
{
	s->stack = (int *)malloc(size * sizeof(int));
	s->top = -1;
	s->size = size;
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
		printf("Error\n");
		exit(1);
	}
	return (s->stack[s->top--]);
}

void	push(stack *s, int item)
{
	if (is_full(s))
	{
		printf("Error\n");
		exit(1);
	}
	s->stack[++s->top] = item;
}

void	sa(stack *a)
{
	int	temp;

	if (a->top < 1)
		return ;
	temp = a->stack[a->top];
	a->stack[a->top] = a->stack[a->top - 1];
	a->stack[a->top - 1] = temp;
	printf("sa");
}

void	sb(stack *b)
{
	int	temp;

	if (b->top < 1)
		return ;
	temp = b->stack[b->top];
	b->stack[b->top] = b->stack[b->top - 1];
	b->stack[b->top - 1] = temp;
	printf("sb");
}

void	ss(stack *a, stack *b)
{
	sa(a);
	sb(b);
	printf("ss");
}

void	pa(stack *a, stack *b)
{
	if (b->top == -1)
		return ;
	push(a, pop(b));
	printf("pa");
}

void	pb(stack *a, stack *b)
{
	if (a->top == -1)
		return ;
	push(b, pop(a));
	printf("pb");
}

void	ra(stack *a)
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
	printf("ra");
}

void	rb(stack *b)
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
	printf("rb");
}

void	rr(stack *a, stack *b)
{
	ra(a);
	rb(b);
	printf("rr");
}

void	rra(stack *a)
{
	int	temp;
	int	i;

	if (a->top == -1)
		return ;
	temp = a->stack[a->top];
	i = a->top;
	while (i > 0)
	{
		a->stack[i] = a->stack[i - 1];
		i--;
	}
	a->stack[0] = temp;
	printf("rra");
}

void	rrb(stack *b)
{
	int	temp;
	int	i;

	if (b->top == -1)
		return ;
	temp = b->stack[b->top];
	i = b->top;
	while (i > 0)
	{
		b->stack[i] = b->stack[i - 1];
		i--;
	}
	b->stack[0] = temp;
	printf("rrb");
}

void	rrr(stack *a, stack *b)
{
	rra(a);
	rrb(b);
	printf("rrr");
}

int	check_sorted(stack *lst)
{
	int	i;

	if (lst->top == -1)
		return (0);
	i = 0;
	while (i < lst->top)
	{
		if (lst->stack[i] > lst->stack[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int is_number(char *str)
{
	int i = 0;
	int len = strlen(str);

	if (len == 0)
		return 0;

	while (i < len)
	{
		if (!isdigit(str[i]))
			return 0;
		i++;
	}

	return 1;
}

int	is_repeated(stack *a, stack *b)
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
	return (0);
}

void	sort_stack(stack *a, stack *b)
{
	int	size;
	int	temp;
	int	i;
	int	j;

	size = a->top + 1;
	i = 0;
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
	printf("\n");
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
			printf("Error\n");
			return (0);
		}
		num = atoi(argv[i]);
		push(&a, num);
		i++;
	}
	if (check_sorted(&a) == 0 || is_repeated(&a, &b) == 1)
	{
		printf("Error\n");
		return (0);
	}
	sort_stack(&a, &b);
	return (0);
}
