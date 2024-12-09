/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {boolean[]}
 */
var isArraySpecial = function(nums, queries) {
    var n = nums.length, q = queries.length;
    const help = Array(n).fill(0)

    for (let i = 1; i < n; ++i)
        help[i] = (((nums[i] ^ nums[i - 1]) & 1) != 0) ? help[i - 1] : i;
    
    const ans = Array(q).fill(false);
    for (let i = 0; i < q; ++i) {
        let f = queries[i][0];
        let t = queries[i][1];
        ans[i] = help[t] <= f;
    }
    return ans;
};