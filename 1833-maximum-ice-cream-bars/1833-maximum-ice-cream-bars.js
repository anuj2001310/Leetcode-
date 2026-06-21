/**
 * @param {number[]} costs
 * @param {number} coins
 * @return {number}
 */
var maxIceCream = function (costs, coins) {
    let n = costs.length;
    let ct = 0;
    costs.sort((a, b) => {
        return a - b;
    });

    for (let i = 0; i < n; i++) {
        let diff = coins - costs[i];
        if (diff < 0)
            break;
        coins -= costs[i];
        ct++;
    }
    return ct;
};