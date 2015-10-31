#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "Stack.h"

//Yufang Sun
//1334960
//mandary@uw.edu

//Help initialize stack
Stack stack_new() {
    Stack newInstance = (Stack)malloc(sizeof(struct stack_st));
    assert(newInstance != NULL);
    newInstance->head = NULL;
    return newInstance;
}

//Delete all elements in Stack s
void stack_delete(Stack s) {
    if (s != NULL) {
        while (s->head != NULL) {
            stack_pop(s);
        }
    }
}

//Push the StackElement element onto Stack s
StackElement stack_push(Stack s, StackElement element) {
    if (s != NULL) {
        Node temp = (Node)malloc(sizeof(struct node_st));
        temp->element = element;
        temp->next = s->head;
        s->head = temp;
        return element;
    }
    return NULL;
}

//Pop the StackElement element from top of Stack s
StackElement stack_pop(Stack s) {
    if (s != NULL) {
        if (s->head != NULL) {
            Node temp = s->head;
            StackElement result = temp->element;
            s->head = s->head->next;
            free(temp);
            temp = NULL;
            return result;
        }
    }
    return NULL;
}