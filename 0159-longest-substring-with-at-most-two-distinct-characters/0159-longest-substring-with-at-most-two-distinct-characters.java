class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        int n = s.length(), l = 0, ans = 1;
        char ch1 = s.charAt(0);
        char ch2 = s.charAt(0);
        int last1 = 0, last2 = -1;
        for (int i = 1; i < n; i++) {
            if (s.charAt(i) == ch1) {
                last1 = i;
            } else if (s.charAt(i) == ch2) {
                last2 = i;
            } else {
                if (last1 < last2) {
                    l = last1 + 1;
                    ch1 = s.charAt(i);

                    last1 = i;
                } else {
                    ch2 = s.charAt(i);
                    l = last2 + 1;

                    last2 = i;
                }
            }

            ans = Math.max(i - l + 1, ans);
        }
        return ans;
    }
}