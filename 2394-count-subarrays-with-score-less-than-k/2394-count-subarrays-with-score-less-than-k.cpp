typedef long long ll;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll res = 0;
        ll sum = 0;
        ll cnt = 0;
        int l = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            cnt++;
            while (sum * cnt >= k) {
                sum -= nums[l++];
                cnt--;
            }
            res += cnt;
        }
        return res;
    }
};