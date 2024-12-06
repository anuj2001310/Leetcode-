public class Solution {
    public int RepeatedNTimes(int[] nums) {
        int[] hash = new int[10001];
        foreach (int num in nums) {
            hash[num]++;
            if (hash[num] >= (nums.Length >> 1))
                return num;
        }
        return -1;
    }
}