class Solution {
private:
    int dfs(vector<int>& nums, int index, int currXOR) {
        if (index == nums.size()) {
            return currXOR;
        }
        int take = dfs(nums, index + 1, currXOR ^ nums[index]);

        int notTake = dfs(nums, index + 1, currXOR);
        return take + notTake;
    }

public:
    int subsetXORSum(vector<int>& nums) { return dfs(nums, 0, 0); }
};