/**
 * @param {number[]} nums
 * @return {boolean}
 */
var checkPrimeFrequency = function(nums) {
    const isPrime = (num) => {
        if (num <= 1)
            return false;
        for (let i = 2; i * i <= num; i++) {
            if (num % i == 0)
                return false;
        }
        return true;
    }
    
    let n = nums.length;
    const map = new Array(101).fill(0);
    
    for (let num of nums)
        map[num]++;
    
    for (let i = 0; i < 101; i++) {
        if (map[i] == 0)
            continue;
        if (isPrime(map[i]))
            return true;
    }
    return false;
};