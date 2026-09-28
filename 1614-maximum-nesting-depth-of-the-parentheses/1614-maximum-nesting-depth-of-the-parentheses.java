class Solution {
    public int maxDepth(String s) {
        int cnt = 0;
        int ans = 0;
        int i = 0;
        while (i < s.length()) {
            if (s.charAt(i) == '(')
                cnt++;
            else if (s.charAt(i) == ')')
                cnt--;
            ans = Math.max(ans, cnt);
            i++;
        }
        return ans;
    }
}