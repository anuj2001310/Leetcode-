class Solution {
public:
    int lb(int n, vector<int>& nums, int target) {
        int l = 0, h = n - 1;
        int ans = -1;
        while (l <= h) {
            int mid = l + ((h - l) >> 1);
            if (nums[mid] == target) {
                ans = mid;
                h = mid - 1;
            } else if (nums[mid] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return ans;
    }

    int ub(int n, vector<int>& nums, int target) {
        int l = 0, h = n - 1;
        int ans = -1;
        while (l <= h) {
            int mid = l + ((h - l) >> 1);
            if (nums[mid] == target) {
                ans = mid;
                l = mid + 1;
            } else if (nums[mid] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return ans;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int l = lb(n, nums, target);
        int u = ub(n, nums, target);
        if (l == -1 || u == -1)
            return {};

        vector<int> ans(u - l + 1);
        iota(ans.begin(), ans.end(), l);

        return ans;
    }
};