public class Solution {
    public int SmallestIndex(int[] nums) {
        int n = nums.Length;
        for (var i = 0; i < n; ++i) {
            var num = nums[i];
            var sum = 0;
            while (num != 0) {
                sum += num % 10;
                if (sum > i)
                    break;
                num /= 10;
            }
            if (sum == i)
                return i;
        }
        return -1;
    }
}