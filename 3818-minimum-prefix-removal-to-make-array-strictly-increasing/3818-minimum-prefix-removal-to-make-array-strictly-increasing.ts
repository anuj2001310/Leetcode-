function minimumPrefixLength(nums: number[]): number {
    let n: number = nums.length;
    for (let i: number = n - 1; i > 0; i--) {
        if (nums[i] <= nums[i - 1])
            return i;
    }
    return 0;
};