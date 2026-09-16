class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int, vector<int>> pq;
        for (int i = 0; i < n; ++i)
            pq.push(stones[i]);
        
        while (pq.size() != 1) {
            int first = pq.top();
            pq.pop();
            int second = 0;
            if (!pq.empty())
                second = pq.top(), pq.pop();
            
            int diff = fabs(first - second);
            pq.push(diff);
        }
        return pq.top();
    }
};