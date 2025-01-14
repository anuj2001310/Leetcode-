typedef pair<int, int> pii;
struct Comp {
    bool operator()(const pii& a, const pii& b) {
        if (a.first == b.first)
            return a.second > b.second;
        return b.first > a.first;
    }
};
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> maps;
        for (int i = 0; i < n; ++i) {
            if (!(nums[i] & 1))
                maps[nums[i]]++;
        }

        if (maps.size() == 0)
            return -1;
        priority_queue<pii, vector<pii>, Comp> pq;
        for (auto& pr : maps)
            pq.push({pr.second, pr.first});
        return pq.top().second;
    }
};