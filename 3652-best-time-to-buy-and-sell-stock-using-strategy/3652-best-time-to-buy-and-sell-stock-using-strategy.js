/**
 * @param {number[]} prices
 * @param {number[]} strategy
 * @param {number} k
 * @return {number}
 */
var maxProfit = function (prices, strategy, k) {
    let n = prices.length
    let original = 0
    let windowSum = 0
    let rightWindowSum = 0
    let mxDiff = 0

    for (let i = 0; i < n; i++) {
        original += strategy[i] * prices[i]
        windowSum += strategy[i] * prices[i]
        if (i >= k / 2)
            rightWindowSum += prices[i]
        let left = i - k + 1
        if (left < 0)
            continue
        mxDiff = Math.max(mxDiff, rightWindowSum - windowSum)
        windowSum -= strategy[left] * prices[left]
        rightWindowSum -= prices[i - k / 2 + 1]
    }

    return original + mxDiff
};