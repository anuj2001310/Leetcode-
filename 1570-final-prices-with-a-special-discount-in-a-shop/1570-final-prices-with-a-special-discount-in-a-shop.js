/**
 * @param {number[]} prices
 * @return {number[]}
 */
var finalPrices = function(prices) {
    let n = prices.length;
    const dis = [];
    for (let i = 0; i < n - 1; i++) {
        let discount = prices[i];
        for (let j = i + 1; j < n; j++) {
            if (prices[j] <= prices[i]) {
                discount = prices[i] - prices[j];
                break;
            }
        }
        dis.push (discount);
    }
    dis.push (prices[n - 1]);
    return dis
};