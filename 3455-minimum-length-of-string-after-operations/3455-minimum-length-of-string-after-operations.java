class Solution {
    public int minimumLength(String s) {
        int n = s.length();
        int[] f = new int[26];
        for (char ch : s.toCharArray())
            f[ch - 'a']++;

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (f[s.charAt(i) - 'a'] > 2)
                f[s.charAt(i) - 'a'] -= 2;
        }
        for (int fr : f)
            res += fr;

        return res;
    }
}