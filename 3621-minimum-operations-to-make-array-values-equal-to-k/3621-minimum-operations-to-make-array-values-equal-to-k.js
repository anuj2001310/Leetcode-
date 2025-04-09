/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minOperations = function(nums, k) {
    let map = Array(101).fill(0);

    for (let num of nums) {
        if (num < k)
            return -1;
        else if (num > k)
            map[num]++;
    }
    let cnt = 0;
    for (let m of map)
        if (m != 0)
            cnt++;
    return cnt;
};