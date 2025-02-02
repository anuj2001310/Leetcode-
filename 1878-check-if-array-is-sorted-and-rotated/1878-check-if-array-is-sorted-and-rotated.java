class Solution {
    public boolean check(int[] nums) {
        int n = nums.length;
        int countBreaks = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] < nums[i])
                countBreaks += 1;
        }
        if (nums[n - 1] > nums[0]) {
            countBreaks++;
        }
        return countBreaks <= 1;
    }
}