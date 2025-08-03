/**
 * @param {number[][]} fruits
 * @param {number} startPos
 * @param {number} k
 * @return {number}
 */
var maxTotalFruits = function (fruits, startPos, k) {
    let n = fruits.length;
    let maxFruits = 0;

    let left = 0;
    while (left < n && fruits[left][0] < startPos - k) 
        left++;

    let right = left;
    let total = 0;

    while (right < n && fruits[right][0] <= startPos + k) {
        total += fruits[right][1];

        while (left <= right) {
            const lPos = fruits[left][0], rPos = fruits[right][0];
            const leftToRight = (startPos - lPos) + (rPos - lPos);
            const rightToLeft = (rPos - startPos) + (rPos - lPos);
            const minSteps = Math.min(leftToRight, rightToLeft);

            if (minSteps <= k) break;
            total -= fruits[left][1];
            left++;
        }

        maxFruits = Math.max(maxFruits, total);
        right++;
    }

    return maxFruits;
};