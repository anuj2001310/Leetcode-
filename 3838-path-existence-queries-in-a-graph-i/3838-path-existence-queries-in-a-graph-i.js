/**
 * @param {number} n
 * @param {number[]} nums
 * @param {number} maxDiff
 * @param {number[][]} queries
 * @return {boolean[]}
 */
var pathExistenceQueries = function(n, nums, maxDiff, queries) {
    let q = queries.length;
    const comp = Array(n).fill(0);
    let cnt = 0;
    for (let i = 1; i < n; i++) {
        if (nums[i] - nums[i - 1] <= maxDiff)
            comp[i] = cnt;
        else
            comp[i] = ++cnt;
    }
    const ans = Array(q).fill(false);
    for (let i = 0; i < q; i++) {
        let u = queries[i][0];
        let v = queries[i][1];
        ans[i] = (comp[u] === comp[v]);
    }
    return ans;
};