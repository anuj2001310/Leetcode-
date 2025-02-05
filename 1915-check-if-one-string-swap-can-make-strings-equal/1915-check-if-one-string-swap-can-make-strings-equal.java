class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        int n = s1.length();
        if (s1.equals(s2))
            return true;
        int cnt = 0;
        int[] a = new int[26];
        int[] b = new int[26];

        for (int i = 0; i < n; i++) {
            if (s1.charAt(i) != s2.charAt(i))
                cnt++;
            int idx1 = s1.charAt(i) - 'a';
            int idx2 = s2.charAt(i) - 'a';
            a[idx1]++;
            b[idx2]++;
        }
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i])
                return false;
        }
        return cnt <= 2;
    }
}