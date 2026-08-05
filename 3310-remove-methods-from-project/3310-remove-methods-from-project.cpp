typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

#define Rep(i, n) for (int i = 0; i < n; i++)

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vvi& invocations) {
        vvi adj(n);
        for (auto& ele : invocations)
            adj[ele[0]].push_back(ele[1]);

        vb visited(n, false);
        queue<int> q;
        q.push(k);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visited[u] = true;
            for (auto& v : adj[u]) {
                if (!visited[v])
                    q.push(v);
            }
        }
        bool flag = false;
        Rep(i, n) {
            if (!visited[i]) {
                for (int& v : adj[i]) {
                    if (visited[v]) {
                        flag = true;
                        break;
                    }
                }
            }
        }
        vector<int> ans;
        if (!flag) { // if no node calls any node in visited component then we
                     // will remove all node visited during BFS call
            Rep(i, n) if (!visited[i]) ans.push_back(i);
        } else
            Rep(i, n) ans.push_back(i);

        return ans;
    }
};