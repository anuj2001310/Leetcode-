char* mapWordWeights(char** words, int n, int* weights, int weightsSize) {
    int i = 0;
    char* ans = (char*)malloc(sizeof(char) * (n + 1));
    char* help = "abcdefghijklmnopqrstuvwxyz";
    for (; i < n; i++) {
        int s = 0;
        char* str = words[i];
        for (; *str; str++)
            s += weights[(*str - 'a')];

        int r = 25 - (s % 26);
        ans[i] = help[r];
    }
    ans[i] = '\0';
    return ans;
}