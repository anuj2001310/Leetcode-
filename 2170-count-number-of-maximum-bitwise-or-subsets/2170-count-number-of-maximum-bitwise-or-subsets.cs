public class Solution {
    int count = 0;
    public int CountMaxOrSubsets(int[] nums) {
        int maxOr = 0;
        foreach (var num in nums) 
            maxOr |= num;
        backtrack(nums, maxOr, 0, 0);
        return count;
    }

    void backtrack(int[] nums, int targetOr, int currOr, int index){
        if(currOr == targetOr) {
            // for pruning the branches in backtracking
            count = count + (1 << (nums.Length - index));
            return;
        }

        for(int i = index; i < nums.Length; i++)
            backtrack(nums, targetOr, currOr | nums[i], i + 1);
    }
}