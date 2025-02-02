class Solution {
    public String findValidPair(String s) {
        int[] freq = new int[10];
        for (char ch : s.toCharArray())
            freq[ch - '0']++;
        int n = s.length();
        String ans = "";
        for (int i = 1; i < n; i++) {
            int cur = s.charAt(i) - '0';
            int pre = s.charAt(i - 1) - '0';
            if (pre == freq[pre] && cur == freq[cur] && cur != pre)
                return ans + pre + cur;
        }
        return ans;
    }
}