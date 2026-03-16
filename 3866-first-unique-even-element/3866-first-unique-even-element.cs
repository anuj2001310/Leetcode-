public class Solution {
    public int FirstUniqueEven(int[] nums) {
        int n = nums.Length;
        var map = new int[101];

        foreach(var num in nums)
            map[num]++;
        for (int i = 0; i < n; ++i) {
            if ((nums[i] & 1) == 0 && map[nums[i]] == 1)
                return nums[i];
        }
        return -1;
    }
}