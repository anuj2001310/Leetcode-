func findMissingElements(nums []int) []int {
    //n := len(nums)
    maxi, mini := math.MinInt, math.MaxInt
    vis := make([]bool, 101)

    for _, num := range nums {
        if num > maxi {
            maxi = num
        }

        if num < mini {
            mini = num
        }
        vis[num] = true
    }
    ans := make([]int, 0)
    for i := mini; i < maxi; i++ {
        if !vis[i] {
            ans = append(ans, i)
        }
    }
    return ans
}