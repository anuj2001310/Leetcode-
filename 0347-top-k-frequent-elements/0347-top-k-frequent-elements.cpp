class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
            map[nums[i]]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for (auto& [k, v] : map) {
            pq.push({v, k});
        }
        map.clear();
        vector<int> ans;
        while (k-- and pq.size()) {
            int x = pq.top().second;
            pq.pop();
            ans.push_back(x);
        }
        return ans;
    }
};