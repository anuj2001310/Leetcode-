class Solution {
    public int countBinarySubstrings(String s) {
        int start = 0, ans = 0;
        char[] arr = s.toCharArray();
        int n = arr.length;
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[i - 1]) {
                ans++;
                start = i - 1;
            } else if (start > 0 && arr[--start] != arr[i])
                ans++;
            else
                start = 0;
        }

        return ans;
    }
}