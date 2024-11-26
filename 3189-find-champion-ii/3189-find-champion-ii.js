/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var findChampion = function(n, edges) {
    const inDeg = Array(n).fill(0);
    for (let i = 0; i < edges.length; ++i) {
        let v = edges[i][1];
        inDeg[v]++;
    }
    let cnt = 0, ans = -1;
    for (let i = 0; i < n; ++i) {
        if (inDeg[i] == 0) {
            cnt++;
            ans = i;
        }
    }
    return cnt === 1 ? ans : -1;
};