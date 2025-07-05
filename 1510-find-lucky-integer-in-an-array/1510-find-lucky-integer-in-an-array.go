func findLucky(arr []int) int {
    hash := make([]int, 501)
    for _, num := range arr {
        hash[num]++
    }

    for i := 500; i > 0; i-- {
        if hash[i] == i {
            return i
        }
    }
    return -1
}