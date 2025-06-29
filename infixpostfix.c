#include <stdio.h>
#include <ctype.h>
#define SIZE 100

char stack[SIZE];
int top = -1;

// Push operation for the stack
void push(char c) {
    if (top == SIZE - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = c;
}

// Pop operation for the stack
char pop() {
    if (top == -1)
        return -1;  // Indicates empty stack
    else
        return stack[top--];
}

// Function to return precedence of operators
int precedence(char c) {
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;  // For non-operators
}

// Function to convert infix to postfix
void infixToPostfix(char* infix) {
    int i = 0;
    char c;
    printf("Postfix Expression: ");
    while (infix[i] != '\0') {
        c = infix[i];

        if (isalnum(c)) {  // Operand (A-Z, a-z, 0-9)
            printf("%c", c);
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                printf("%c", pop());
            pop(); // Remove '('
        } else {  // Operator
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                printf("%c", pop());
            push(c);
        }
        i++;
    }

    // Pop remaining operators from the stack
    while (top != -1)
        printf("%c", pop());

    printf("\n");
}

int main() {
    char infix[SIZE];
    printf("Enter Infix Expression: ");
    scanf("%s", infix);  // Accept infix expression (no spaces)

    infixToPostfix(infix);

    return 0;
}
