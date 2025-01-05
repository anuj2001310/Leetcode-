char* shiftingLetters(char* s, int** shifts, int shiftsSize, int* shiftsColSize) {
    int n = strlen(s);
    int prefix[n + 1] = {};

    for (uint i = 0; i < shiftsSize; i++) {
        int s = shifts[i][0];
        int e = shifts[i][1];
        int d = shifts[i][2];

        prefix[s] += (2 * d - 1);
        prefix[e + 1] -= (2 * d - 1);
    }

    int curr = 0;
    for (int i = 0; i < n; i++) {
        curr = (curr + prefix[i]) % 26;
        s[i] = 'a' + (s[i] - 'a' + curr + 26) % 26;
    }
    return s;
}