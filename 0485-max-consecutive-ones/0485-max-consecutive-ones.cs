public class Solution {
    public int FindMaxConsecutiveOnes(int[] nums) {
        var temp = 0;
        var ans = 0;
        for (var i = 0; i < nums.Length; ++i) {
            if (nums[i] == 1) {
                temp++;
                ans = Math.Max(ans, temp);
            }
            else
                temp = 0;
        }
        return ans;
    }
}