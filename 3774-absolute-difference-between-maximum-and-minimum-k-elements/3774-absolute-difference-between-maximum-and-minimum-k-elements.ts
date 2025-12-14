function absDifference(nums: number[], k: number): number {
    nums.sort((a, b) => {
        return a - b;
    });
    let s: number = 0, f: number = 0;
    let n: number = nums.length;
    
    for (let i: number = 0; i < k; i++) {
        s += nums[i];
        f += nums[n - i - 1];
    }
    return f - s;
};