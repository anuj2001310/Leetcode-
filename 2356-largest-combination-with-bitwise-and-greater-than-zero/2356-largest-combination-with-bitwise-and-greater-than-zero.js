/**
 * @param {number[]} candidates
 * @return {number}
 */
var largestCombination = function(candidates) {
    const freq = Array(32).fill(0);
    var ans = 0
    const dp = (num) => {
        for (let i = 0; i < 32; ++i) {
            let m = 1 << i
            if (m & num)
                freq[i]++
            ans = Math.max(ans, freq[i])
        }
    }

    for(let num of candidates)
        dp(num)
    
    return ans
};