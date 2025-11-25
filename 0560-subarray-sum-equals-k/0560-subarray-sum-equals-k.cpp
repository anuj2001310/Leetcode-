class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        int cnt = 0, sum = 0;
        int r = 0;
        map[sum] = 1;

        for (; r < n; ++r) {
            sum += nums[r];
            if (map.find(sum - k) != map.end())
                cnt += map[sum - k];
            map[sum]++;
        }
        return cnt;
    }
};