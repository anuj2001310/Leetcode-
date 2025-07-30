class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0, ans = 0, currentStreak = 0;

        for (int num : nums) {
            if (maxVal < num) {
                maxVal = num;
                ans = currentStreak = 0;
            }

            if (maxVal == num)
                currentStreak++;
            else
                currentStreak = 0;

            ans = fmax(ans, currentStreak);
        }
        return ans;
    }
};