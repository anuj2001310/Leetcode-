class Solution {
    private boolean v(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    public String trimTrailingVowels(String s) {
        int n = s.length();
        int i = n - 1;
        while (i >= 0) {
            if (!v(s.charAt(i)))
                break;
            i--;
        }
        return s.substring(0, i + 1);
    }
}