int countOddLetters(int n) {
    char* arr[10] = {"zero", "one", "two",   "three", "four",
                     "five", "six", "seven", "eight", "nine"};
    int freq[26] = {};

    for (; n; n /= 10) {
        int r = n % 10;
        char *p = arr[r];   // temporary pointer

        for (; *p; p++)
            freq[*p - 'a']++;
    }

    int c = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] == 0)
            continue;
        c += ((freq[i] & 1));
    }
    return c;
}