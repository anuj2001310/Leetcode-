public class Solution {
    public int MaximumPossibleSize(int[] nums) {
        var n = nums.Length;
        var cnt = 1;
        int num = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] >= num) {
                cnt++;
                num = nums[i];
            }
        }
        return cnt;
    }
}