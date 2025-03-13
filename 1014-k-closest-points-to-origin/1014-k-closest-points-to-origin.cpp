typedef vector<int> vi;
typedef pair<int, vi> pivi;
class Solution {
private:
    int distance(int x, int y) { 
        return pow(x, 2) + pow(y, 2);
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pivi, vector<pivi>, greater<pivi>> pq;
        for (int i = 0; i < n; ++i) {
            int x = points[i][0];
            int y = points[i][1];
            int dis = distance(x, y);
            pq.push({dis, points[i]});
        }

        vector<vector<int>> ans;
        while (k-- > 0 && !pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            ans.push_back(curr.second);
        }

        return ans;
    }
};