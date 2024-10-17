int findLUSlength(char* a, char* b) {
    return (!strcmp(a, b)) ? -1 : fmax(strlen(a), strlen(b));
}