#include <stdlib.h>
#include <string.h>

// Check vowel
int isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Count vowels in a word
int vowelCount(char* s, int start, int end) {
    int count = 0;
    for (int i = start; i < end; i++) {
        if (isVowel(s[i]))
            count++;
    }
    return count;
}

// Reverse characters between start and end
void reverse(char* s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

char* reverseWords(char* s) {
    int n = strlen(s);

    // First word vowel count
    int i = 0;
    while (i < n && s[i] != ' ')
        i++;
    int firstVowels = vowelCount(s, 0, i);

    // Process remaining words
    int start = i + 1;
    while (start < n) {
        int end = start;
        while (end < n && s[end] != ' ')
            end++;

        int vc = vowelCount(s, start, end);
        if (vc == firstVowels)
            reverse(s, start, end - 1);

        start = end + 1;
    }

    return s;
}