/**
 * @param {number[][]} matrix
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function (matrix, k) {
    const flattenMatrix = matrix.flat();
    const sortedFlattenMatrix = flattenMatrix.sort((a, b) => a - b);

    return sortedFlattenMatrix[k - 1];
};