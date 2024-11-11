public class Solution {
    public int SumIndicesWithKSetBits(IList<int> nums, int k) {
        int n = nums.Count;
        var sum = 0;
        int bits(int num) {
            var b = 0;
            while (num != 0) {
                num &= (num - 1);
                b++;
            }
            return b;
        }

        for (int i = 0; i < n; ++i) {
            if (bits(i) == k)
                sum += nums[i];
        }
        return sum;
    }
}