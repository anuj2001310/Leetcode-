function longestOnes(nums: number[], k: number): number {
    let n: number = nums.length;
    let l: number = 0, r: number = 0, ans: number = -1, zero: number = 0;
    for (; r < n; r++) {
        if (nums[r] == 0)
            zero++;

        while (zero > k) {
            if (nums[l++] == 0)
                zero--;
        }
        let curr: number = r - l + 1;
        if (curr > ans)
            ans = curr;
    }
    return ans;
};