using vi = vector<int>;

class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n = size(nums);
        vi map(101, 0);
        for (int i = 0; i < n; ++i)
            map[nums[i]]++;

        for (int i = 0; i < n; ++i) {
            if (nums[i] & 1)
                continue;
            
            if (map[nums[i]] == 1)
                return nums[i];
        }
        return -1;
    }
};