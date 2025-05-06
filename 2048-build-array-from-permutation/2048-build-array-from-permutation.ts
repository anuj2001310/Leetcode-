function buildArray(nums: number[]): number[] {
    let n = nums.length;
    let ans = Array(n).fill(0);
    for (let i = 0; i < n; ++i)
        ans[i] = nums[nums[i]];
    
    return ans;
};