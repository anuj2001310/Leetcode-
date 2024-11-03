bool rotateString(char* s, char* goal) {
    if (strlen(s) != strlen(goal))
        return false;
    int n = strlen(s);
    char concat[2 * n + 1];

    strcpy(concat, s);
    strcat(concat, s);
    
    return strstr(concat, goal);
}