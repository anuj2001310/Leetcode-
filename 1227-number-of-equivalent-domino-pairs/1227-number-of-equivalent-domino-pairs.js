/**
 * @param {number[][]} dominoes
 * @return {number}
 */
var numEquivDominoPairs = function(dominoes) {
    let hash = Array(100).fill(0);
    let cnt = 0;
    for (let pair of dominoes) {
        let u = pair[0];
        let v = pair[1];
        let num = (u > v) ? v * 10 + u : u * 10 + v;
        cnt += hash[num];

        hash[num]++;
    }
    return cnt;
};