class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        vector<pair<int, int>> pairs;
        for (auto& vec : intervals) {
            int x = vec[0], y = vec[1] + 1;
            pairs.push_back({x, 1});
            pairs.push_back({y, -1});
        }
        sort(pairs.begin(), pairs.end());
        int cnt = 0, x = 0;
        for (auto& [_, f] : pairs) {
            x += f;
            cnt = fmax(cnt, x);
        }

        return cnt;
    }
};