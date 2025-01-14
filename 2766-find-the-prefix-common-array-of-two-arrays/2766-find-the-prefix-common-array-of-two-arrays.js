/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number[]}
 */
var findThePrefixCommonArray = function(A, B) {
    let n = A.length;
    const ans = []
    const pa = Array(n + 1).fill(false)
    const pb = Array(n + 1).fill(false)
    var cnt = 0

    for (let i = 0; i < n; i++) {
        cnt += A[i] == B[i] ? 1 : 0;
        cnt += pa[B[i]] ? 1 : 0;
        cnt += pb[A[i]] ? 1 : 0;

        pa[A[i]] = true
        pb[B[i]] = true
        ans.push(cnt)
    }
    return ans
};