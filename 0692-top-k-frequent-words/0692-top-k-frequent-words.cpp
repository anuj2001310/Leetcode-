class Solution {
    using pii = pair<int, int>;
    using pis = pair<int, string>;
    using psi = pair<string, int>;

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string, int> map;
        for (int i = 0; i < n; i++)
            map[words[i]]++;

        vector<psi> pq(map.begin(), map.end());
        sort(pq.begin(), pq.end(), [&](const psi& a, const psi& b) {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
        });

        vector<string> ans;
        for (int i = 0; i < pq.size() and k--; i++)
            ans.push_back(pq[i].first);
        return ans;
    }
};