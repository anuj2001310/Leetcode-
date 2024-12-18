/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function (nums, k) {
    const map = new Map();
    nums.forEach((i) => {
        map.set(i, (map.get(i) || 0) + 1)
    })
    const arr = [];
    map.forEach((value, key) => {
        arr.push([key, value]);
    });


    return arr.sort((a, b) => b[1] - a[1])
        .slice(0, k)
        .map((i) => i[0]);
};