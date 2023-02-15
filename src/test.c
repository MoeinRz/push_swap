#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    int *stack;
    int top;
    int size;
} stack;

void init_stack(stack *s, int size) {
    s->stack = (int *)malloc(size * sizeof(int));
    s->top = -1;
    s->size = size;
}

int is_empty(stack *s) {
    return s->top == -1;
}

int is_full(stack *s) {
    return s->top == s->size - 1;
}

int pop(stack *s) {
    if (is_empty(s)) {
        printf("Error\n");
        exit(1);
    }
    return s->stack[s->top--];
}

void push(stack *s, int item) {
    if (is_full(s)) {
        printf("Error\n");
        exit(1);
    }
    s->stack[++s->top] = item;
}
void	free_stack(stack *s)
{
	free(s->stack);
	s->stack = NULL;
	s->top = -1;
	s->size = 0;
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

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(stack *a, stack *b, int low, int high) {
    int pivot = a->stack[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a->stack[j] > pivot) {
            i++;
            swap(&a->stack[i], &a->stack[j]);
        }
    }
    swap(&a->stack[i+1], &a->stack[high]);
    return i + 1;
}

void quick_sort(stack *a, stack *b, int low, int high) {
    if (low < high) {
        int pivot_index = partition(a, b, low, high);
        quick_sort(a, b, low, pivot_index - 1);
        quick_sort(a, b, pivot_index + 1, high);
    }
}

void sort_stack(stack *a, stack *b) {
    quick_sort(a, b, 0, a->top);
}

void swaps(stack *s, char c) {
int temp;

if (c == 'a') {
    temp = s->stack[s->top];
    s->stack[s->top] = s->stack[s->top - 1];
    s->stack[s->top - 1] = temp;
} else if (c == 'b') {
    temp = s->stack[s->top];
    s->stack[s->top] = s->stack[s->top + 1];
    s->stack[s->top + 1] = temp;
}
}

int partitionA(stack *a, stack *b, int low, int high)
{
int pivot;
int i, j;

if (c == 'a')
    pivot = a->stack[high];
else if (c == 'b')
    pivot = b->stack[high];

i = low - 1;

for (j = low; j < high; j++)
{
    if (c == 'a' && a->stack[j] > pivot)
    {
        i++;
        swaps(a, 'a');
    }
    else if (c == 'b' && b->stack[j] < pivot)
    {
        i++;
        swaps(b, 'b');
    }
}

if (c == 'a')
    swaps(a, 'a');
else if (c == 'b')
    swaps(b, 'b');

return (i + 1);
}

void quick_sortA(stack *a, stack *b, int low, int high) {
if (low < high) {
int pivot_index = partitionA(a, b, low, high);
quick_sortA(a, b, low, pivot_index - 1);
quick_sortA(a, b, pivot_index + 1, high);
}
}

void sort_stackA(stack *a, stack *b) {
    quick_sortA(a, b, 0, a->top);
}
int main(int argc, char *argv[]) {
    if (argc == 1)
        return 0;
    stack a, b;
    init_stack(&a, argc - 1);
    init_stack(&b, argc - 1);
    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);
        push(&a, num);
    }
    sort_stackA(&a, &b);
    printf("Sorted Stack (Descending Order): ");
    while (!is_empty(&a)) {
        printf("%d ", pop(&a));
    }
    printf("\n");
    return 0;
}


