bool doesAliceWin(char* s) {
    while (*s) {
        switch (*s) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            break;
        }
        *s++;
    }
    return false;
}