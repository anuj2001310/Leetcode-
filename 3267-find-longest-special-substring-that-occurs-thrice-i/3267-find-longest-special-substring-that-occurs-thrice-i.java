class Solution {
    public int maximumLength(String s) {
        int l = 0, r = 1, n = s.length();
        int[][] arr = new int[26][60];
        int ans = -1;

        while (r <= n) {
            while (r < n && s.charAt(r) == s.charAt(l))
                r++;
            for (int i = r - 1; i >= l; --i) {
                int len = i - l + 1;
                arr[s.charAt(l) - 'a'][len] += r - i;
                if (arr[s.charAt(l) - 'a'][len] > 2 && len > ans)
                    ans = len;
            }
            l = r;
            r++;
        }
        return ans;
    }
}