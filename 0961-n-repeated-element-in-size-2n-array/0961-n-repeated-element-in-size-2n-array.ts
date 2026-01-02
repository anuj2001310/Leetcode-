function repeatedNTimes(nums: number[]): number {
    let n: number = nums.length;
    const s = new Set();
    for (let i: number = 0; i < 2 * n; ++i) {
        if (s.has(nums[i]))
            return nums[i];
        
        s.add(nums[i]);
    }
    return -1;
};