int maximumLength(char* s) {
    int ans = -1, len = strlen(s), cnt = 0;
    int chs[26][4] = {};
    int chsSize[26] = {};
    for (int i = 0; i < len; i++) {
        cnt++;
        if (i + 1 == len || s[i] != s[i + 1]) {
            int ch = s[i] - 'a';
            chs[ch][chsSize[ch]] = cnt;
            chsSize[ch]++;
            cnt = 0;
            for (int j = chsSize[ch] - 1; j > 0; j--) {
                if (chs[ch][j] > chs[ch][j - 1]) {
                    int temp = chs[ch][j];
                    chs[ch][j] = chs[ch][j - 1];
                    chs[ch][j - 1] = temp;
                } else
                    break;
            }
            if (chsSize[ch] > 3)
                chsSize[ch]--;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (chsSize[i] > 0 && chs[i][0] > 2)
            ans = fmax(ans, chs[i][0] - 2);
        if (chsSize[i] > 1 && chs[i][0] > 1)
            ans = fmax(ans, fmin(chs[i][0] - 1, chs[i][1]));
        if (chsSize[i] > 2)
            ans = fmax(ans, chs[i][2]);
    }
    return ans;
}