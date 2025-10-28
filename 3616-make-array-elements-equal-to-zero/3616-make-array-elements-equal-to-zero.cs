public class Solution {
    public int CountValidSelections(int[] nums)    {
        int[] leftsum = new int[nums.Length];
        int[] rightsum = new int[nums.Length];

        leftsum[0] = nums[0];
        for (int i = 1; i < nums.Length; i++)
            leftsum[i] = leftsum[i-1]+ nums[i];
        
        rightsum[nums.Length - 1] = nums[nums.Length - 1];
        for (int i = nums.Length - 2; i >= 0; i--)
            rightsum[i] = rightsum[i + 1] + nums[i];
        int result = 0;
        for (int i = 0; i < nums.Length; i++) {
            if (nums[i] == 0) {
                if (leftsum[i] == rightsum[i]) 
                    result += 2;
                else if (int.Abs(leftsum[i] - rightsum[i]) == 1) 
                    result++;
            }
        }
        return result;
    }
}