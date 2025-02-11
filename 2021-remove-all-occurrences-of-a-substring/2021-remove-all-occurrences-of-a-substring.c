#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* removeOccurrences(char* s, char* part) {
    int len1 = strlen(s);
    int len2 = strlen(part);
    int ind = 0;
    char* stack = malloc(len1 + 1);
    for (int i = 0; i < len1; i++) {
        stack[ind++] = s[i];
        int count = 0;
        if (ind >= len2) {
            for (int j = 0; j < len2; j++) {
                if (stack[ind - len2 + j] == part[j])
                    count++;
            }
            if (count == len2)
                ind -= len2;
        }
    }
    stack[ind] = '\0';
    return stack;
}