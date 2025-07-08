#include <stdio.h>
#include <stdlib.h>
#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char c) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = c;
}

// Pop operation
char pop() {
    if (top == -1)
        return '\0';  // Indicates underflow or mismatch
    return stack[top--];
}

// Function to check if opening and closing brackets match
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check if expression is valid
int isValid(char expr[]) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[')
            push(c);
        else if (c == ')' || c == '}' || c == ']') {
            char popped = pop();
            if (!isMatchingPair(popped, c))
                return 0;  // Mismatched closing bracket
        }
    }
    return (top == -1);  // Stack should be empty if valid
}

int main() {
    char expr[MAX];

    printf("Enter expression with brackets: ");
    scanf("%s", expr);

    if (isValid(expr))
        printf("The expression is VALID (Balanced stack operations).\n");
    else
        printf("The expression is INVALID (Unbalanced stack operations).\n");

    return 0;
}
