/**
 * @param {number} n
 * @return {number}
 */
var mirrorDistance = function (n) {
    return Math.abs(n - +String(n).split``.reverse().join``);
};