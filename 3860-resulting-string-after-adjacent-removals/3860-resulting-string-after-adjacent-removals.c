char* resultingString(char* s) {
    bool func(char x, char y) {
        int val = fabs(x - y);
        return val == 1 || val == 25;
    }
    
    int n = strlen(s);
    char* stack = (char*)malloc(n + 1);
    int top = -1;

    for (int i = 0; i < n; i++) {
        if (top >= 0 && func(stack[top], s[i]))
            top--;  
        else
            stack[++top] = s[i];
        
    }
    stack[top + 1] = '\0';
    return stack;
}