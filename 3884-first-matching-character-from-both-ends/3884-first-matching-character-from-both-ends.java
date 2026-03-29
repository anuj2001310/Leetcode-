class Solution {
    public int firstMatchingIndex(String s) {
        int n = s.length();
        int l = 0, r = n - 1;
        while (l <= r) {
            if (s.charAt(l++) == s.charAt(r--))
                return l - 1;
        }
        return -1;
    }
}