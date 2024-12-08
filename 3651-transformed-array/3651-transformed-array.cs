public class Solution {
    public int[] ConstructTransformedArray(int[] nums) {
        int n = nums.Length;
        int[] res = new int[n];
        int j = 0;
        for (int i = 0; i < n; ++i) {
            int idx = (i + nums[i] % n + n) % n;
            res[j++] = nums[idx];
        }
        return res;
    }
}