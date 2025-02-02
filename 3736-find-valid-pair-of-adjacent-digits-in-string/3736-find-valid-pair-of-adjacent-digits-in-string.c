#include <stdio.h>
#include <string.h>

char* findValidPair(char* s) {
    static char ans[3];
    int arr[10] = {};

    for (int i = 0; s[i] != '\0'; i++)
        arr[s[i] - '0']++;

    int n = strlen(s);
    
    for (int i = 1; i < n; i++) {
        int cur = s[i] - '0';
        int pre = s[i - 1] - '0';
        
        if (arr[pre] == pre && arr[cur] == cur && pre != cur) {
            ans[0] = s[i - 1];
            ans[1] = s[i];
            ans[2] = '\0';
            return ans;
        }
    }

    ans[0] = '\0';
    return ans;
}
