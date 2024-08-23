#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Node * newNode(int data){
    Node * node = (Node *)malloc(sizeof(Node)); //Allocates the memory for the new node, alocates for the size of the struct Node
    node->data = data; //the data value is set on the parameters. 
    node->next = NULL; //The pointer points to null, that shows that the node doesn't points to another node
    return node;
}

Stack * newStack(){
    Stack * stack = (Stack *)malloc(sizeof(Stack)); //Allocates the memory for the new stack, alocates for the size of the struct Stack
    stack->top = NULL; //Initialize the top as null, what shows that the stack is Empty
    stack->size = 0; //As the stack is empty, the stack's size is zero
    return stack;
}

int isEmpty(Stack *stack){
    return stack->size == 0; //Return 1 if the stack is equal 0, showing that the stack is empty
}

int pop(Stack *stack){
    if(isEmpty(stack) == 1){ //Verify whether the stack is empty or not
        printf("The stack is empty!\n"); //If undewflow (if the stack has no nodes) shows error message 
        return 1; //Return 1 indicates an error
    }   

    Node * tempNode = stack->top; //stores the top node in an temporary tempNode
    int data = tempNode->data; //Create a variable to store the tempnode data
    stack->top = tempNode->next; //Change the top of the stack to the next node in the stack 
    stack->size--; //Resize the stack after removing a value

    free(tempNode); //Free the memory that tempnode alocated
    return data; 
}

int getSize(Stack *stack){ //Function that returns the size of the stack
    return stack->size; //Return the stack size (The stack struct size)
}

void push(Stack *stack, int data) {
    Node *node = newNode(data); // Create a new node with data
    node->next = stack->top; //The top of the stack is moved to the next position
    stack->top = node; //The node created with data is movedo to the top of the stack
    stack->size++; //Resize the stack
}

void printStack(Stack * stack){
    Stack * auxStack = newStack(); //create auxStack to temporarily hold the elements of the original stack (stack)
    //during the printing process
    
    printf("[ ");
    
    while (isEmpty(stack) == 0){ //While the stack is not empty/
        int data = pop(stack); //he top element of stack is popped and stored in data. 
        //Remove the top element so the loop repeat itself showing the NEXT number, meanwhile the popped number is stored in data
        push(auxStack, data); //The top element is then pushed onto the auxiliary stack (auxStack) and printed.
        printf("%d ", data);
    }

     while (isEmpty(auxStack) == 0){ //While the stack is not empty
        int data = pop(auxStack); //The top element of auxStack is popped and pushed back onto the original stack (stack).
        push(stack, data);
    }
    printf(" ]");
    free(auxStack); //Free all the alocated memory
}
