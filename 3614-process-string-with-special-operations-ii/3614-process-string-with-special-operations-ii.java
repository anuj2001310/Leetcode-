class Solution {
    public char processStr(String s, long k) {
        int n = s.length();

        long[] len = new long[n];
        long curLen = 0;

        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);

            if (c >= 'a' && c <= 'z') {
                curLen++;
            } else if (c == '*') {
                if (curLen > 0)
                    curLen--;
            } else if (c == '#') {
                curLen *= 2;
            } else {
            }

            len[i] = curLen;
        }

        if (k >= curLen)
            return '.';

        for (int i = n - 1; i >= 0; i--) {
            char c = s.charAt(i);

            long before = (i == 0 ? 0 : len[i - 1]);

            if (c >= 'a' && c <= 'z') {
                if (k == before)
                    return c;
            } else if (c == '#') {
                if (before > 0)
                    k %= before;
            } else if (c == '%') {
                k = before - 1 - k;
            } else {
            }
        }

        return '.';
    }
}