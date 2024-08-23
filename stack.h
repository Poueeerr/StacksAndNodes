#ifndef STACK_H
#define STACK_H

typedef struct  Node //Create the typedef struct as Node
{
    int data; //Create the var that will hold all the Nodes Data
    struct Node* next; //This pointer point to the next Node in the stack
    
} Node; //Alias for struct node

typedef struct //Create struct for the stack
{
    int size; //Create the var that holds the size of the stack
    Node *top; //This pointer point to the top node in the stack
} Stack;


Stack * newStack(); //Allocates and initializes a new Stack structure and returns a pointer to it

Node * newNode(int data); //Creates a new Node with the given data and returns a pointer to it

void push(Stack *stack, int data); //Adds a new node with the given data to the top of the stack.
// Returns an integer to indicate success or failure

int pop(Stack *stack); //Removes and returns the data from the top node of the stack. 
//The function returns the popped value, or some error indicator if the stack is empty

void printStack(Stack*stack); //Prints all the elements from the stack, from top to bottom
int isEmpty(Stack *stack);
#endif 