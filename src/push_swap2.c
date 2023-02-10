/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:02:59 by mrezaei           #+#    #+#             */
/*   Updated: 2023/02/09 16:18:33 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

// Stack structure to store numbers
struct Stack {
int data[MAX_SIZE];
int top;
};

// Push function to add an element to the top of the stack
void push(struct Stack *stack, int item) {
if (stack->top < MAX_SIZE - 1) {
stack->data[++stack->top] = item;
}
}

// Pop function to remove the top element from the stack
int pop(struct Stack *stack) {
if (stack->top >= 0) {
return stack->data[stack->top--];
}
return -1;
}

// Swap function to swap the first two elements at the top of the stack
void swap(struct Stack *stack) {
if (stack->top >= 1) {
int temp = stack->data[stack->top];
stack->data[stack->top] = stack->data[stack->top - 1];
stack->data[stack->top - 1] = temp;
}
}

// Rotate function to shift all elements up by one
void rotate(struct Stack *stack) {
if (stack->top >= 1) {
int temp = stack->data[stack->top];
for (int i = stack->top; i > 0; i--) {
stack->data[i] = stack->data[i - 1];
}
stack->data[0] = temp;
}
}

// Reverse rotate function to shift all elements down by one
void reverse_rotate(struct Stack *stack) {
if (stack->top >= 1) {
int temp = stack->data[0];
for (int i = 0; i < stack->top; i++) {
stack->data[i] = stack->data[i + 1];
}
stack->data[stack->top] = temp;
}
}

// Push to stack a function to add an element to the top of stack a from stack b
void push_to_a(struct Stack *a, struct Stack *b) {
if (b->top >= 0) {
push(a, pop(b));
}
}

// Push to stack b function to add an element to the top of stack b from stack a
void push_to_b(struct Stack *a, struct Stack *b) {
if (a->top >= 0) {
push(b, pop(a));
}
}

// Main function
int main(int argc, char *argv[]) {
// Check if there are any parameters
if (argc < 2) {
return 0;
}

struct Stack a, b;
a.top = -1;
b.top = -1;

// Read the parameters and store them in stack a
for (int i = 1; i < argc; i++) {
int item = atoi(argv[i]);
push(&a, item);
}

// Sort stack a using the operations described above

// Your code for sorting stack a here