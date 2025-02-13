class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        int op = 0;
        for (auto& it : nums)
            pq.push(it);

        while (pq.size() > 1 && pq.top() < k) {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            long long new_num = x * 2 + y;
            pq.push(new_num);
            op++;
        }

        return op;
    }
};