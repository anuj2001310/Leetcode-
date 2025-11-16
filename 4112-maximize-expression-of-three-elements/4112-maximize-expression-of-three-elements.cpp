class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int firstMaximum = numeric_limits<int>::min();
        int secondMaximum = numeric_limits<int>::min();
        int minimum = numeric_limits<int>::max();
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (nums[i] >= firstMaximum) {
                secondMaximum = firstMaximum;
                firstMaximum = nums[i];
            }
            else if (nums[i] > secondMaximum && nums[i] != firstMaximum)
                secondMaximum = nums[i];
            
            minimum = fmin(minimum, nums[i]);
        }
        return firstMaximum + secondMaximum - minimum;
    }
};