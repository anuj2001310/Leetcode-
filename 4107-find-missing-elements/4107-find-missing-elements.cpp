class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        
        int maxi = std::numeric_limits<int>::min();
        int mini = std::numeric_limits<int>::max();
        vector<bool> vis(101, false);
        
        for (int g = 0; g < n; g++) {
            maxi = fmax(maxi, nums[g]);
            mini = fmin(mini, nums[g]);
            vis[nums[g]] = true;
        }
        vector<int> res;
        for (int i = mini; i < maxi; ++i) {
            if (!vis[i])
                res.push_back(i);
        }
        return res;
    }
};