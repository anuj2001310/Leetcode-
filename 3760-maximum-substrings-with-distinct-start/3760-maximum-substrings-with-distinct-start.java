class Solution {
    public int maxDistinct(String s) {
        int n = s.length();
        int cnt = 0;
        int[] arr = new int[26];
        for (int i = 0; i < n; ++i) {
            char ch = s.charAt(i);
            if (arr[ch - 'a'] == 0)
                cnt++;
            arr[ch - 'a']++;
        }
        return cnt;
    }
}