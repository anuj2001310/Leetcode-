/**
 * @param {number[][]} isConnected
 * @return {number}
 */
var findCircleNum = function(isConnected) {
    var V = isConnected.length;
    let ans = 0;
    const vis = Array(V).fill(false);

    const dfs = (node) => {
        vis[node] = true;
        for (let j = 0; j < V; ++j) {
            if (isConnected[node][j] === 1 && !vis[j])
                dfs (j);
        }
    }

    for (let i = 0; i < V; ++i) {
        if (!vis[i]) {
            ans++;
            dfs (i);
        }
    }
    return ans;
};