using pii = pair<int, int>;
using node = pair<int, pii>;
// using node = tuple<int, int, int>;

class Solution {
private:
    class cmp {
    public:
        bool operator()(const node& a, const node& b) {
            if (a.first == b.first) {
                if (a.second.first == b.second.first)
                    return a.second.second > b.second.second;
                return a.second.first > b.second.first;
            }
            return b.first > a.first;
        }
    };

public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center,
                          int radius) {
        int n = size(towers);
        priority_queue<node, vector<node>, cmp> pq;
        for (int i = 0; i < n; ++i) {
            int x = towers[i][0];
            int y = towers[i][1];
            int q = towers[i][2];
            bool flag = false;
            int dis = abs(x - center[0]) + abs(y - center[1]);
            if (dis <= radius) {
                if (flag && q >= pq.top().first &&
                    (x < pq.top().second.first || y < pq.top().second.second))
                    pq.push({q, {x, y}});
                else {
                    pq.push({q, {x, y}});
                    flag = true;
                }
            }
        }
        if (pq.empty())
            return {-1, -1};

        return {pq.top().second.first, pq.top().second.second};
    }
};