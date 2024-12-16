class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int i = 0; i < n; i++)
            minHeap.push({nums[i], i});

        while (k--) {
            auto [value, index] = minHeap.top();
            nums[index] = nums[index] * multiplier;
            minHeap.pop();
            minHeap.push({nums[index], index});
        }
        return nums;
    }
};