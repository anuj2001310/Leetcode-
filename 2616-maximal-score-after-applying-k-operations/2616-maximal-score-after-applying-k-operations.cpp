class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq;
        for (auto& num : nums)
            pq.push(num);

        while (pq.size() && k--) {
            auto top = pq.top();
            pq.pop();
            ans += top;
            top = ceil((double)top / 3);
            pq.push(top);
        }
        return ans;
    }
};