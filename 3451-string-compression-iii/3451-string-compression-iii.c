char* compressedString(char* word) {
    int index = 0, count = 1, n = strlen(word), i = 1;
    char* comp = (char*)malloc((2 * n + 1) * sizeof(char));
    char prev = word[0];
    while (i < n) {
        if (word[i] != prev) {
            index += sprintf(&comp[index], "%d%c", count, prev);
            prev = word[i];
            count = 1;
        } else {
            if (count == 9) {
                index += sprintf(&comp[index], "%d%c", count, prev);
                count = 1;
            } else
                count++;
        }
        i++;
    }
    index += sprintf(&comp[index], "%d%c", count, prev);
    comp[index] = '\0';
    return comp;
}