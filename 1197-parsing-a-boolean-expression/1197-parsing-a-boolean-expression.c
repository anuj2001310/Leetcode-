#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool parseBoolExpr(char* expression) {
    char stack[2000];
    int top = -1;

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if (ch == ',' || ch == '(') {
            continue;
        }

        if (ch == 't' || ch == 'f' || ch == '!' || ch == '&' || ch == '|') {
            stack[++top] = ch;
        } else if (ch == ')') {
            bool hasTrue = false, hasFalse = false;
            while (stack[top] == 't' || stack[top] == 'f') {
                if (stack[top] == 't') {
                    hasTrue = true;
                } else {
                    hasFalse = true;
                }
                top--; // Pop the current value
            }

            char operator= stack[top--]; // Pop the operator

            bool result;
            if (operator== '&') {
                result = !hasFalse;
            } else if (operator== '|') {
                result = hasTrue;
            } else { // '!'
                result = !hasTrue;
            }

            // Push result back as 't' or 'f'
            stack[++top] = result ? 't' : 'f';
        }
    }

    return stack[0] == 't';
}