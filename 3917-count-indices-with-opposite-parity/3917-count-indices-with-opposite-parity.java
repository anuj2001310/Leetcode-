class Solution {
    public int[] countOppositeParity(int[] nums) {
        int n = nums.length;
        var ans = new int[n];

        int even = 0, odd = 0;
        for (int num : nums) {
            if ((num & 1) == 0)
                even++;
            else
                odd++;
        }

        for (int i = 0; i < n; i++) {
            if ((nums[i] & 1) == 0)
                even--;
            else
                odd--;
            
            if ((nums[i] & 1) == 0)
                ans[i] = odd;
            else
                ans[i] = even;
        }
        return ans;
    }
}