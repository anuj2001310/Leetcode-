public class Solution {
    public int count(int n) {
        int b = 0;
        while (n != 0) {
            n = n & (n - 1);
            b++;
        }
        return b;
    }
    public bool CanSortArray(int[] nums) {
        var l = 0;
        var h = nums[0];
        bool bit;
        for (var i = 1; i < nums.Length; ++i) {
            bit = (count(h) != count(nums[i]));
            if (bit) 
                l = h;
            if (nums[i] > h)
                h = nums[i];
            if (nums[i] < l)
                return false;
        }
        return true;
    }
}