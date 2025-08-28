#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

// Stack structure
int stack[MAX];
int top = -1;

// Stack operations
void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Function to perform arithmetic operations
int evaluate(char operator, int op1, int op2) {
    switch (operator) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        case '^': return (int)pow(op1, op2);
        default:
            printf("Invalid operator: %c\n", operator);
            exit(1);
    }
}

// Main evaluation function
int evaluatePostfix(char* expr) {
    int i;
    for (i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (isspace(ch)) continue;

        // If operand (digit), push to stack
        if (isdigit(ch)) {
            push(ch - '0');  // convert char to int
        }
        // If operator, pop 2 elements and evaluate
        else {
            int op2 = pop();
            int op1 = pop();
            int result = evaluate(ch, op1, op2);
            push(result);
        }
    }

    // Final result
    return pop();
}

// Main
int main() {
    char expr[100];

    printf("Enter postfix expression (e.g., 53+82-*): ");
    scanf("%s", expr);

    int result = evaluatePostfix(expr);
    printf("Result = %d\n", result);

    return 0;
}

