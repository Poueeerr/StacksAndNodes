#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    int data, n, opc;
    Stack *stack = newStack(); //Create the stack 
    
    int temp = isEmpty(stack); //Store if the stack is empty or not
    printf("Is the stack empty? (0 = False, 1 = True)\n%d\n", temp);

    printf("How many numbers do you want in the stack?\n");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        printf("Push number %d: ", i); //For loop to add numbers into the stack
        scanf("%d", &data);
        push(stack, data);
    }

    printStack(stack);

    printf("Do you wish to use pop? (0 = No, 1 = Yes) \n");
    scanf("%d", &opc);

    switch (opc) {
    case 1:
        pop(stack);
        printStack(stack);
        temp = isEmpty(stack);
        printf("Is the stack empty after pop? (0 = False, 1 = True)\n%d\n", temp);
        break;
    case 0:
        printf("Ok\n");
        break;
    default:
        printf("Invalid option.\n");
        break;
    }

    // Free the allocated memory for the stack (and its nodes if necessary)
    free(stack);

    return 0;
}
