import java.util.Arrays;

class Solution {

    public String generateString(String str1, String str2) {

        int n = str1.length();
        int m = str2.length();
        char c1[] = str1.toCharArray();
        char c2[] = str2.toCharArray();
        char res[] = new char[n + m - 1];
        Arrays.fill(res, '?');
        int len = n + m - 1;
        boolean filled[] = new boolean[n + m - 1];

        for (int i = 0; i < n; i++) {
            if (c1[i] == 'F') {
                continue;
            }
            for (int j = 0; j < m; j++) {
                int pos = i + j;
                if (res[pos] == '?' || res[pos] == c2[j]) {
                    res[pos] = c2[j];
                    filled[pos] = true;
                } else {
                    return "";
                }
            }
        }

        for (int i = 0; i < len; i++) {
            if (res[i] == '?') {
                res[i] = 'a';
            }
        }

        for (int i = 0; i < n; i++) {
            if (c1[i] == 'T') {
                continue;
            }
            if (!eq(res, i, c2, m)) {
                continue;
            }
            int j = m - 1;
            for (j = m - 1; j >= 0; j--) {
                int pos = i + j;
                if (!filled[pos]) {
                    filled[pos] = true;
                    res[pos] = 'b';
                    break;
                }
            }

            if (j == -1)
                return "";
        }

        return new String(res);
    }

    private boolean eq(char res[], int start, char c2[], int len) {
        for (int j = 0; j < len; j++) {
            if (res[start + j] != c2[j])
                return false;
        }

        return true;
    }
}