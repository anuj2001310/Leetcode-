#define ll long long
using umil = unordered_map<int, ll>;
class Solution {
public:
    ll countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        umil map;
        map[0] = 1; 

        ll res = 0;
        int cur = 0; 

        for (int& num : nums) {
            if (num % modulo == k)
                cur++;

            int mod = cur % modulo;

            int target = (mod - k + modulo) % modulo;
            if (map.find(target) != map.end())
                res += map[target];

            map[mod]++;
        }

        return res;
    }
};