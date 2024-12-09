func isArraySpecial(nums []int, queries [][]int) []bool {
    n, q := len(nums), len(queries)

    help := make([]int, n)
    for i := 1; i < n; i++ {
        if (nums[i] ^ nums[i - 1]) & 1 != 0 {
            help[i] = help[i - 1]
        } else {
            help[i] = i
        }
    }

    ans := make([]bool, q)
    for i := 0; i < q; i++ {
        f := queries[i][0]
        t := queries[i][1]
        ans[i] = help[t] <= f
    }
    return ans
}