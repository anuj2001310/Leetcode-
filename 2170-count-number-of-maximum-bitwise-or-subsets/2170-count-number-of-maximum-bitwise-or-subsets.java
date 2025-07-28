class Solution {
    public int countMaxOrSubsets(int[] nums) {
        int maxOrValue = 0;
        for (int num : nums) {
            maxOrValue |= num;
        }

        int totalSubsets = 1 << nums.length;
        int subsetsWithMaxOr = 0;

        for (int subsetMask = 0; subsetMask < totalSubsets; subsetMask++) {
            int currentOrValue = 0;

            for (int i = 0; i < nums.length; i++) {
                if (((subsetMask >> i) & 1) == 1)
                    currentOrValue |= nums[i];
            }

            if (currentOrValue == maxOrValue) {
                subsetsWithMaxOr++;
            }
        }

        return subsetsWithMaxOr;
    }
}