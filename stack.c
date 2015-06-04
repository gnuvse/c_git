#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack {
	int top;
	int maxsize;
	int *data;
} typedef Stack;

void init (Stack*, int);
void push (Stack*, int);
int pop (Stack*);
bool is_empty (Stack*);
bool is_full (Stack*);
void print_stack (Stack*);
int size (Stack*);
void delete_stack (Stack*);





int main () {
	int i;
	Stack *st = (Stack*) malloc (sizeof (Stack));

	int n;
	scanf ("%d", &n);
	init (st, n);
	int tmp;

	for (i = 0; i < n; ++i) {
		scanf ("%d", &tmp);
		push (st, tmp);
	}

	print_stack (st);
	pop (st);
	pop (st);
	pop (st);
	print_stack (st);
	push (st, 100);
	print_stack (st);
	delete_stack(st);

	return 0;
}

bool is_empty (Stack *s) {
	if (s->top == 0)
		return 1;

	return 0;
}

bool is_full (Stack *s) {
	if (s->top == s->maxsize)
		return 1;

	return 0;
}

void push(Stack *s, int a) {
	if (is_full (s)) {
		printf ("Stack is overflowed\n");
		exit(1);
	}

	s->data[s->top] = a;
	s->top++;
	return;
}

void init (Stack *s, int n) {
	s->maxsize = n;
	s->data = (int*) malloc (sizeof (int) * s->maxsize);
	s->top = 0;

	return;
}

int pop (Stack *s) {
	if(is_empty(s)) {
		printf("Stack is empty.\n");
		exit(1);
	}

	int pop_var = s->data[s->top-1];
	s->top--;

	return pop_var;
}

int size (Stack *s) {
	return s->top;
}

void print_stack (Stack *s) {
	int i;
	printf ("\nStack:\n");

	for (i = 0; i < s->top; i++)
		printf("%i ", s->data[i]);

	printf("\n");

	return;
}

void delete_stack (Stack *s) {
	free(s->data);

	return;
}

