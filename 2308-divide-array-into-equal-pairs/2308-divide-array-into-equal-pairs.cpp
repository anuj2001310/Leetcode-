class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(501, false);
        for (int i = 0; i < n; ++i)
            vis[nums[i]] = !vis[nums[i]];
        for (int i = 0; i < 501; ++i)
            if (vis[i])
                return false;
        return true;
    }
};