typedef long long ll;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll ans = 0;
        int n = nums.size(), l = 0;
        int max = *max_element(nums.begin(), nums.end());
        int curr = 0;
        for (int r = 0; r < n; r++) {
            curr += (nums[r] == max);
            while (curr >= k)
                curr -= (nums[l++] == max);
            ans += l;
        }
        return ans;
    }
};