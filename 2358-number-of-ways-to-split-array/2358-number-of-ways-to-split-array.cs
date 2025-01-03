public class Solution {
    public int WaysToSplitArray(int[] nums) {
        long rsum = 0;
        long lsum = 0;
        foreach (var num in nums)
            rsum += num;
        
        int cnt = 0;
        for (var i = 0; i < nums.Length - 1; i++) {
            lsum += nums[i];
            rsum -= nums[i];

            if (lsum >= rsum)
                cnt++;
        }
        return cnt;
    }
}