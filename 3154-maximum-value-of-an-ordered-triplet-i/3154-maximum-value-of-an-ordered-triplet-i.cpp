class Solution {
    typedef long long ll;

public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0, imax = 0, dmax = 0;
        for (int i = 0; i < n; ++i) {
            ans = fmax(ans, dmax * nums[i]);
            dmax = fmax(dmax, imax - nums[i]);
            imax = fmax(imax, nums[i]);
        }
        return ans;
    }
};