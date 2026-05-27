class Solution {
    public int numberOfSpecialChars(String word) {
        int n = word.length();
        var llst = new int[26];
        var ulst = new int[26];
        for (int i = 0; i < 26; ++i) {
            llst[i] = -1;
            ulst[i] = -1;
        }
        var vis = new boolean[26];

        for (int i = 0; i < n; i++) {
            if (word.charAt(i) >= 'a' && word.charAt(i) <= 'z')
                llst[word.charAt(i) - 'a'] = i;
        }

        for (int i = n - 1; i >= 0; i--)
            if (word.charAt(i) >= 'A' && word.charAt(i) <= 'Z')
                ulst[word.charAt(i) - 'A'] = i;

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int idx = 0;
            if (word.charAt(i) >= 'a' && word.charAt(i) <= 'z')
                idx = word.charAt(i) - 'a';
            else
                idx = word.charAt(i) - 'A';
            if (llst[idx] != -1 && ulst[idx] != -1 && ulst[idx] > llst[idx] &&
                    !vis[idx])
                cnt++;
            vis[idx] = true;
        }
        return cnt;

    }
}