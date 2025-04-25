class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> map;
        map[0] = 1; 

        long long res = 0;
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