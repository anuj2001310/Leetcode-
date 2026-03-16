function firstUniqueEven(nums: number[]): number {
    let n: number = nums.length;
    const arr: number[] = new Array(101).fill(0);
    for (let num of nums)
        arr[num]++;

    for (let i: number = 0; i < n; ++i) {
        if ((nums[i] & 1) == 0 && arr[nums[i]] == 1)
            return nums[i]
    }
    return -1;
};