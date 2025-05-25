class Solution {
    using pii = pair<int, int>;
    using pipii = pair<int, pii>;

private:
    struct cmp {
        bool operator()(const pii& a, const pii& b) {
            if (a.first == b.first)
                return b.second > a.second;
            return a.first > b.first;
        }
    };

public:
    int findClosestNumber(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pii, vector<pii>, cmp> pq;
        for (int i = 0; i < n; i++) {
            int num = fabs(nums[i] - 0);
            pq.push({num, nums[i]});
        }
        return pq.top().second;
    }
};