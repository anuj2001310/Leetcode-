/**
 * @param {number[]} nums
 * @param {number} limit
 * @return {number[]}
 */
var lexicographicallySmallestArray = function (nums, limit) {
    const n = nums.length;
    const help = [];

    for (let i = 0; i < n; i++) {
        help.push([nums[i], i]);
    }

    help.sort((a, b) => a[0] - b[0]);

    const res = new Array(n);
    let prev = -Infinity;
    let pos = [];

    let s = 0, e = 0;
    while (e < n) {
        pos.push(help[e][1]);
        prev = help[e][0];
        e++;

        if (e === n || help[e][0] - prev > limit) {
            pos.sort((a, b) => a - b);
            for (let idx of pos) {
                res[idx] = help[s][0];
                s++;
            }
            pos = [];
        }
    }

    return res;
};

