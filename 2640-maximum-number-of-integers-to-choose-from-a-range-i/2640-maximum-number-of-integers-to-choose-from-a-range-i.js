/**
 * @param {number[]} banned
 * @param {number} n
 * @param {number} maxSum
 * @return {number}
 */
var maxCount = function(banned, n, maxSum) {
    const hash = Array(10001).fill(false)
    for (let num of banned)
        hash[num] = true;
    
    let sum = 0, cnt = 0;
    for (let i = 1; i <= n; ++i) {
        if (!hash[i]) {
            sum += i;
            if (sum <= maxSum)
                cnt++;
            else
                return cnt;
        }
        else
            continue;
    }
    return cnt;
};