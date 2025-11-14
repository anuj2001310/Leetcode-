class Solution {
    typedef long long ll;
    
public:
    long long maxProduct(vector<int>& nums) {
        int n = size(nums);
        int cnt = 0;
        ll ans = 1e5;
        //cout<<ans<<endl;
        ll first = -ans, second = -ans;
        for (auto r = 0; r < n; ++r) {
            if (nums[r] != 0)
                cnt++;

            if (fabs(nums[r]) >= first) {
                second = first;
                first = fabs(nums[r]);
            }
            else if (fabs(nums[r]) > second && fabs(nums[r]) != first)
                second = fabs(nums[r]);
        }

        if (cnt <= n / 3)
            return 0;
        
        return fabs(first * second * ans);
    }
};