/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number[]} values
 * @param {number} k
 * @return {number}
 */
var maxKDivisibleComponents = (n, e, v, k) => {
    
    tree_dp = (cur, par) => {
        let subTreeSum = v[cur];
        for (const child of g[cur]) {
            if (child != par) {
                tree_dp(child, cur);
                subTreeSum += m[child];
            }
        }
        m[cur] = subTreeSum;
        r += subTreeSum % k == 0
    }

    r = 0
    m = Array(n).fill(0)
    g = m.map(_ => [])
    e.map(([u, v]) => g[u].push(v) && g[v].push(u))
    tree_dp(0, -1)
    return r
};