class Solution {
    public long zeroFilledSubarray(int[] nums) {
        int n = nums.length;
        long res = 0;
        long temp = 0, maxcount = 0;

        boolean flag = false;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0)
                temp++;
            else {
                maxcount = temp;
                temp = 0;
                flag = true;
            }
            
            if (flag) {
                res = res + (maxcount * (maxcount + 1) >> 1);
                flag = false;
            }
        }
        if (temp != 0)
            res += (temp * (temp + 1) >> 1);

        return res;
    }
}