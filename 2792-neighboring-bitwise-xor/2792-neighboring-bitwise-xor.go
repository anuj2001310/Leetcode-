func doesValidArrayExist(derived []int) bool {
    ans := 0
    for _, num := range derived {
        ans ^= num
    }

    return ans == 0
}