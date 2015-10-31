#ifndef STACK_H
#define STACK_H

// The types Stack and StackElement are not defined
// in this skeletal Stack.h file.  You should decide
// what their types should be and define them here.

#define StackElement void*

typedef struct node_st {
	StackElement element;
	struct node_st *next;
} * Node;

typedef struct stack_st{
	Node head;
} * Stack;


// These are the public methods that unit-tests.c
// depends upon.  
Stack        stack_new();
void         stack_delete(Stack s);
StackElement stack_push(Stack s, StackElement element);
StackElement stack_pop(Stack s);

#endif // STACK_H
