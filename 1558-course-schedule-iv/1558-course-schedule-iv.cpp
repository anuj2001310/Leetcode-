typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& pre, vector<vector<int>>& qry) {
        vvi adj(num);
        vi indegree(num, 0);
        vvb reach(num, vb(num, false));
        for (auto& e : pre) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < num; i++) {
            if (indegree[i] == 0)
                q.push (i);
        }

        vi top;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            top.push_back(node);
            for (auto& neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                    q.push (neigh);
            }
        }

        for (auto& cse : top) {
            for (auto& neigh : adj[cse]) {
                reach[cse][neigh] = true;
                for (int i = 0; i < num; i++) {
                    if (reach[i][cse])
                        reach[i][neigh] = true;
                }
            }
        }

        vb ans;
        for (auto& q : qry)
            ans.push_back(reach[q[0]][q[1]]);
        return ans;
    }
};