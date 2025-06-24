class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> keyIndices;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == key)
                keyIndices.push_back(i);
        }

        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            for (auto& j : keyIndices) {
                if (abs(i - j) <= k) {
                    result.push_back(i);
                    break;
                }
            }
        }
        return result;
    }
};