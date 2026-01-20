class Solution {
    private boolean isV(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                ch == 'u';
    }
    private boolean isC(char ch) {
         if (ch >= 'a' && ch <= 'z' && !isV(ch))
                return true;
            return false;
    }
    public int vowelConsonantScore(String s) {
        int n = s.length();
        int v = 0, c = 0;
        for (char ch : s.toCharArray()) {
            if (isV(ch))
                v++;
            if (isC(ch))
                c++;
        }

        int score = (c == 0) ? 0 : v / c;
        return score;
    }
}