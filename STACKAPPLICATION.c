#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;
void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return -1;
}

void infixToPostfix(char* infix) {
    int i = 0;
    char c;
    while(infix[i] != '\0') {
        c = infix[i];
        if(isalnum(c)) { // operand
            printf("%c", c);
        } else if(c == '(') {
            push(c);
        } else if(c == ')') {
            while(top != -1 && stack[top] != '(')
                printf("%c", pop());
            pop(); // pop '('
        } else { // operator
            while(top != -1 && precedence(stack[top]) >= precedence(c))
                printf("%c", pop());
            push(c);
        }
        i++;
    }
    while(top != -1)
        printf("%c", pop());
}

int main() {
    char infix[MAX];
    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    printf("Postfix Expression: ");
    infixToPostfix(infix);

    return 0;
}
