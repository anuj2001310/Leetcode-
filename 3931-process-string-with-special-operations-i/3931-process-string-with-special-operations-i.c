#include <stdlib.h>
#include <string.h>

#define MAXR  (1<<20)   // ~1 048 576 chars, safe for s.length ≤ 20

char* processStr(char* s) {
    static char result[MAXR];
    int len = 0;

    for (int i = 0; s[i]; ++i) {
        char ch = s[i];

        if (ch >= 'a' && ch <= 'z') {
            result[len++] = ch;
        }
        else if (ch == '*') {
            if (len > 0) --len;
        }
        else if (ch == '#') {
            if (len > 0) {
                // duplicate the current [0..len-1]
                memcpy(result + len, result, len);
                len <<= 1;  // len *= 2
            }
        }
        else if (ch == '%') {
            // in-place reverse [0..len-1]
            for (int l = 0, r = len - 1; l < r; ++l, --r) {
                char tmp = result[l];
                result[l] = result[r];
                result[r] = tmp;
            }
        }
    }

    result[len] = '\0';
    return result;
}