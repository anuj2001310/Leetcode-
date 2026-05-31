/**
 * @param {number} n
 * @return {number}
 */
var digitFrequencyScore = function(n) {
    return (n <= 0) ? 0 : (n % 10 + digitFrequencyScore(Math.floor(n / 10)));
};