public class Solution {
    public int SubsetXORSum(int[] nums) {
        int c = 0, n = nums.Length;
        foreach (var num in nums)
            c |= num;
        
        return c << (n - 1);
    }
}