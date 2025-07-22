class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, r = 0;
        int n = nums.size();
        int ans = 0, res = 0;

        unordered_map<int, int> map;

        for (; r < n; r++) {
            map[nums[r]]++;
            ans += nums[r];

            while (map[nums[r]] >= 2)
                map[nums[l]]--, ans -= nums[l++];
                
            res = fmax(res, ans);
        }

        return res;
    }
};