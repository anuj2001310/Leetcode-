class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int numsSize = size(nums);
        bool* vis = (bool*)calloc(sizeof(bool), 101);

        for (int i = 0; i < numsSize; ++i)
            vis[nums[i]] = true;
        int ans = k;
        for (; ans < 101; ans += k) {
            if (ans % k == 0 && !vis[ans]) {
                free(vis);
                return ans;
            }
        }
        free(vis);
        return ans;
    }
};