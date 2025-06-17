func specialTriplets(nums []int) int {
    n := len(nums)
    MOD := 1000000007
    max := func(nums []int) int {
        f := 0
        for i := 0; i < n; i++ {
            if nums[i] > f {
                f = nums[i]
            }
        }
        return f
    }

    size := 2 * max(nums) + 1
    left := make([]int64, size)
    right := make([]int64, size)

    for _, num := range nums {
        right[num]++
    }
    var ans int64

    for j := 0; j < n; j++ {
        right[nums[j]]--
        val := 2 * nums[j]
        lval := left[val]
        rval := right[val]

        ans = ((int64(ans) + (lval * rval)) % int64(MOD))
        left[nums[j]]++
    }

    return int(ans)
}