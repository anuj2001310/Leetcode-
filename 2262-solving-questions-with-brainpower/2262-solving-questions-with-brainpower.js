/**
 * @param {number[][]} questions
 * @return {number}
 */
var mostPoints = function(questions) {
    let n = questions.length;
    const dp = Array(n + 1).fill(-1);
    
    const memo = (idx) => {
        if (idx >= n)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        let take = questions[idx][0];
        let nidx = idx + questions[idx][1] + 1;
        
        if (nidx < n)
            take += memo(nidx);
        let skip = memo(idx + 1);
        
        return dp[idx] = Math.max(take, skip);
    }
    
    return memo(0);
};