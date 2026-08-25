class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> vis(101, false);
        for (int i = 0; i < n; i++)
            vis[nums[i]] = true;
        int ans = k;
        for (; ans < 101; ans += k) {
            if (ans % k == 0 and !vis[ans])
                return ans;
        }
        return ans;
    }
};