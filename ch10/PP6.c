// Reverse Polish Notation (RPN) Calculator

#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK 100

double stack[MAXSTACK];
int sp = 0; // Stack pointer

void push(double f) {
    if (sp < MAXSTACK) {
        stack[sp++] = f;
    } else {
        printf("Error: Stack full, can't push %g\n", f);
    }
}

double pop() {
    if (sp > 0) {
        return stack[--sp];
    } else {
        printf("Error: Stack empty\n");
        return 0.0;
    }
}

int main() {
    char input[100];
    double op2;

    printf("Enter RPN expression (e.g., '3 4 +'):\n");
    while (scanf("%s", input) == 1) {
        if (input[0] >= '0' && input[0] <= '9') {
            push(atof(input)); // Convert string to double and push
        } else {
            switch (input[0]) {
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '/':
                    op2 = pop();
                    if (op2 != 0.0) {
                        push(pop() / op2);
                    } else {
                        printf("Error: Division by zero\n");
                    }
                    break;
                default:
                    printf("Error: Unknown command %s\n", input);
            }
        }
    }

    printf("Result: %g\n", pop());
    return 0;
}