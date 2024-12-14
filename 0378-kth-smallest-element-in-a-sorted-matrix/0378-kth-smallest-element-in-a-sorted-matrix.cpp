typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

class Solution {
/*
private:
    struct Compare {
        bool operator()(pipii x, pipii y) {
            if (x.first > y.first)
                return true;
            return false;
        }
    };
*/
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;

        vis[0][0] = true;
        pq.push({matrix[0][0], {0, 0}});
        while (--k && pq.size() > 0) {
            int val = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if (r + 1 < n and !vis[r + 1][c]) {
                vis[r + 1][c] = true;
                pq.push({matrix[r + 1][c], {r + 1, c}});
            }
            if (c + 1 < m and !vis[r][c + 1]) {
                vis[r][c + 1] = true;
                pq.push({matrix[r][c + 1], {r, c + 1}});
            }
        }
        return pq.top().first;
    }
};