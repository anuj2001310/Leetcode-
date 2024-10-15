class Solution {
    public long minimumSteps(String s) {
        long ans = 0, swap = 0;
        for (char ch : s.toCharArray()) {
            if (ch == '1')
                swap++;
            else
                ans += swap;
        }
        return ans;
    }
}