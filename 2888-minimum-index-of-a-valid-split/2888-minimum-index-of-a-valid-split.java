class Solution {
    public int minimumIndex(List<Integer> nums) {

        int x = nums.get(0), cnt = 0, xCount = 0, n = nums.size();

        for (int num : nums) {
            if (num == x)
                cnt++;
            else
                cnt--;
            if (cnt == 0) {
                x = num;
                cnt = 1;
            }
        }

        for (int num : nums) {
            if (num == x)
                xCount++;
        }

        cnt = 0;
        for (int idx = 0; idx < n; idx++) {
            if (nums.get(idx) == x)
                cnt++;

            int remainingCount = xCount - cnt;
            if (cnt * 2 > idx + 1 && remainingCount * 2 > n - idx - 1)
                return idx;
        }

        return -1;
    }
}