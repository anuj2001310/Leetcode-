class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = INT_MAX;
        int sum = 0;

        for (int x : nums) {
            mini = min(mini, x);
            sum += x;
        }

        return sum - (nums.size() * mini);
    }
};