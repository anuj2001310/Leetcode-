func divideArray(nums []int) bool {
    vis := make ([]bool, 501)
    for _, num := range nums {
        vis[num] = !vis[num]
    }
    for i := 0; i < 501; i++ {
        if vis[i] {
            return false
        }
    }
    return true
}