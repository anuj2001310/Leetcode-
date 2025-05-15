class Solution {
    public List<String> getLongestSubsequence(String[] a, int[] g) {
        List<String> ans = new ArrayList<>();
        int n = g.length;
        if (n == 1) {
            ans.add(a[0]);
            return ans;
        }
        int p = -1;
        for (int i = 0; i < n; i++) {
            if (g[i] != p) {
                p = g[i];
                ans.add(a[i]);
            }
        }
        if (ans.size() == 0) {
            ans.add(a[0]);
            return ans;
        }
        return ans;
    }
}