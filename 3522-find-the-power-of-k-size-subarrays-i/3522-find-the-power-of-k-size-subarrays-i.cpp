class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> res(len - k + 1, -1);
        deque<int> indexDeque;
        for (int i = 0; i < len; i++) {
            if (!indexDeque.empty() && indexDeque.front() < i - k + 1)
                indexDeque.pop_front();

            if (!indexDeque.empty() && nums[i] != nums[i - 1] + 1)
                indexDeque.clear();

            indexDeque.push_back(i);

            if (i >= k - 1) {
                if (indexDeque.size() == k)
                    res[i - k + 1] = nums[indexDeque.back()];
            }
        }
        return res;
    }
};