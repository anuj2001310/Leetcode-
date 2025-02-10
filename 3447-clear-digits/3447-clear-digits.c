bool isDigit(char c) { return c >= '0' && c <= '9'; }
char* clearDigits(char* s) {
    int length = strlen(s);
    int indices[length];
    int indicesCount = 0;

    // Find indices of digits
    for (int i = 0; i < length; i++) {
        if (isDigit(s[i])) {
            indices[indicesCount++] = i;
        }
    }

    char result[length + 1];
    int resultIndex = 0;

    // Remove digits and closest non-digit characters
    for (int i = 0; i < length; i++) {
        bool isDigitToRemove = false;
        for (int j = 0; j < indicesCount; j++) {
            if (i == indices[j]) {
                isDigitToRemove = true;
                break;
            }
        }

        if (!isDigitToRemove) {
            result[resultIndex++] = s[i];
        } else {
            int left = i - 1;
            while (left >= 0 && !((s[left] >= 'a' && s[left] <= 'z') ||
                                  (s[left] >= 'A' && s[left] <= 'Z'))) {
                left--;
            }
            if (left >= 0) {
                resultIndex--;
            }
        }
    }

    result[resultIndex] = '\0';
    return strdup(result);
}