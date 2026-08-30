class Solution {
    public int minimumDeletions(int[] nums) {
        int min_idx = 0;
        int max_idx = 0;
        int min = nums[0];
        int max = nums[0];
        int n = nums.length;
        for(int i  =  0 ; i < n ; ++i){
            if(nums[i] < min){
                min_idx = i;
                min = nums[i];
            }
            if(nums[i] > max){
                max_idx = i;
                max = nums[i];
            }

        }
        int rightToLeft = 0;
        int leftToRight = 0;
        int fromBothSide = 0;
        leftToRight = Math.max(min_idx,max_idx) + 1;
        rightToLeft = n - Math.min(min_idx,max_idx);
        fromBothSide = (Math.min(min_idx,max_idx)) + (n - Math.max(min_idx,max_idx)) + 1;
        return Math.min(rightToLeft,Math.min(leftToRight,fromBothSide));
    }
}