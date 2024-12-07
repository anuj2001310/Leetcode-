class Solution {
    public int minimumSize(int[] nums, int maxOperations) {
        int max_val = 0;
        for (int x : nums)
            max_val = Math.max(max_val, x);

        int l = 1, r = max_val;
        while (l <= r) {
            int m = ((r - l) >> 1) + l;
            int cnt = 0;
            for (int x : nums)
                cnt += (x - 1) / m;
            if (cnt > maxOperations)
                l = m + 1;
            else
                r = m - 1;
        }
        return l;
    }
}