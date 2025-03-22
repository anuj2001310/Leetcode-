/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var countCompleteComponents = function(n, edges) {
    const adj = Array(n).fill().map(() => []);

    for (let [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u); 
    }

    let cnt = 0;
    const vis = new Array(n).fill(false);

    for (let i = 0; i < n; i++) {
        if (!vis[i]) {
            const comp = [];
            const queue = [i];
            vis[i] = true;

            while (queue.length > 0) {
                const node = queue.shift();
                comp.push(node);

                for (let neigh of adj[node]) {
                    if (!vis[neigh]) {
                        vis[neigh] = true;
                        queue.push(neigh);
                    }
                }
            }

            let flag = true;
            for (let ele of comp) {
                if (adj[ele].length !== comp.length - 1) {
                    flag = false;
                    break;
                }
            }
            if (flag) 
                cnt++;
        }
    }

    return cnt;
};
