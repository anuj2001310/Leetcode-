class Solution {
    public int[] buildArray(int[] nums) {
        int n = nums.length;
        int[] sms = new int[n];

        for (int i = 0; i < n; ++i)
            sms[i] = nums[nums[i]];
            
        return sms;
    }
}