public class Solution {
    public bool Check(int[] nums) {
        var cnt = 0;
        var n = nums.Length;
        for (var i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1])
                cnt++;
        }
        if (nums[n - 1] > nums[0])
            cnt++;
        return cnt <= 1;
    }
}