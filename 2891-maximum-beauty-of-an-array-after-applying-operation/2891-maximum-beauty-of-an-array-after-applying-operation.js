/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumBeauty = function (nums, k) {
    const freq = Array(100001).fill(0);
    let xMax = 0, xMin = 1e6;
    for (let x of nums) {
        freq[x]++;
        xMax = Math.max(x, xMax);
        xMin = Math.min(x, xMin);
    }
    let cnt = 0, maxCnt = 0;
    for (let l = xMin, r = xMin; r <= xMax; r++) {
        cnt += freq[r];
        while (r - l > 2 * k) {
            cnt -= freq[l];
            l++;
        }
        maxCnt = Math.max(maxCnt, cnt);
    }
    return maxCnt;
};