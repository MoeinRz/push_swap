/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:03:06 by mrezaei           #+#    #+#             */
/*   Updated: 2023/02/16 17:59:01 by mrezaei          ###   ########.fr       */
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
	s->stack = (int *)malloc(size * sizeof(int));
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
	if (s->top == -1)
		return (-1);
	else
		return (s->top);
}

int	is_full(stack *s)
{
	return (s->top == s->size - 1);
}

void	ptest(stack *s)
{
	int	i;

	if (s == NULL)
	{
		printf("Error: Stack is null\n");
		return ;
	}
	i = s->top;
	if (is_empty(s) == -1)
	{
		printf("Stack is empty\n");
		return ;
	}
	// printf("Stack elements from top to bottom: ");
	while (i >= 0)
	{
		printf("%d ", s->stack[i]);
		i--;
	}
	printf("\n");
	// printf("The top is : %d\n", s->top);
}

int	pop(stack *s)
{
	int	tmp;

	tmp = 0;
	if (is_empty(s) == -1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	tmp = s->stack[s->top];
	// printf("The address of the top is : %p\n", &s->stack[s->top]);
	// printf("The address of the top is : %p\n", &tmp);
	s->top--;
	return (tmp);
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
	s->top++;
	s->stack[s->top] = item;
//	s->stack[++(s->top)] = item;
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
		return ;
	push_end(a, pop(b));
	printf("pa\n");
}

void	pb(stack *a, stack *b)
{
	int	 temp;

	temp = 0;
	if (a->top == -1)
		return;
	push_end(b, pop(a));
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
///////////////////////////////////////////////////////////
int		get_pivot(int *arr, int start, int end)
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

void	partition0(stack *a, stack *b, int start, int end)
{
	if (start >= end)
		return ;
	int	pivot_index;
	int	pivot_value;
	int	i;
	int	temp;

	temp = 0;
	pivot_index = get_pivot(a->stack, start, end);
	pivot_value = a->stack[pivot_index];
	// printf("marhale1---------------------->, PI=%d, PV=%d\n", pivot_index, pivot_value);
	// ptest(a);
	// ptest(b);
	i = a->size;
	while (i)
	{
	// printf("***** i= %d\n", i);
	// ptest(a);
	// ptest(b);

		if (a->stack[a->top] < pivot_value)
			pb(a, b);
		else if (a->stack[a->top] == pivot_value)
			pop(a);
		// else if (a->top == pivot_index)
		// 	rra(a);
		else if (a->stack[a->top] > pivot_value)
			ra(a);
		i--;
		
	}
	push_end(a, pivot_value);
	// printf("marhale----------------------------->2  \n");
	// ptest(a);
	// ptest(b);
	while (b->top >= 0)
	{
		pa(a, b);
	}
	// printf("marhale----------------------------->3  \n");
	// ptest(a);
	// ptest(b);
	partition0(a, b, start, pivot_index - 1);
	partition0(a, b, pivot_index + 1, end);
}

void	quicksort(stack *a, stack *b)
{
	int	start;
	int	end;

	start = 0;
	partition0(a, b, start, a->top);
	return ;
}

/// @brief ////////////////////////////////////
/// @param a 
/// @param b 
/*
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(stack *a, stack *b, int low, int high)
{
	int pivot = a->stack[high];
	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (a->stack[j] > pivot) {
			i++;
			swap(&a->stack[i], &a->stack[j]);
			ptest(a);
		}
	}
	swap(&a->stack[i+1], &a->stack[high]);
	return (i + 1);
}

void quick_sort(stack *a, stack *b, int low, int high) {
	if (low < high) {
		int pivot_index = partition(a, b, low, high);
		quick_sort(a, b, low, pivot_index - 1);
		quick_sort(a, b, pivot_index + 1, high);
	}
}
*/
/// @brief ////////////////////////////////////////////////
/// @param a 
/// @param b /

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
		quicksort(a, b);
		return ;
	}
}

int	main(int argc, char *argv[])
{
	stack	a;
	stack	b;
	int		i;
	int		num;

	// char *my_argv[] = {"program_name", "-1", "2", "8", "5", "80", "-25"};
	// argc = sizeof(my_argv) / sizeof(char *);
	// argv = my_argv;
	
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

	printf("a=");
	ptest(&a);


	sort_stack(&a, &b);

	printf("a=");
	ptest(&a);



	free_stack(&a);
	free_stack(&b);
	return (0); 
}
