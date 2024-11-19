/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    const arr = Array(31).fill(-1);
    arr[0] = 0;
    arr[1] = 1;
    const memo = (n) => {
        if (n === 0 || n === 1)
            return n
        if (arr[n] !== -1)
            return arr[n]
        
        return arr[n] = memo(n - 1) + memo(n - 2)
    }
    return memo(n)
};