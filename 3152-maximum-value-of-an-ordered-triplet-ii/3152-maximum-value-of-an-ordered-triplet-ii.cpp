typedef long long ll;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0, dmax = 0, imax = 0;
        for (int i = 0; i < n; ++i) {
            ans = fmax(ans, dmax * nums[i]);
            dmax = fmax(dmax, imax - nums[i]);
            imax = fmax(imax, nums[i]);
        }
        return ans;
    }
};