func threeConsecutiveOdds(arr []int) bool {
    cnt, mask := 0, 1 << 1
    for _, num := range arr {
        if num & 1 != 0 {
            cnt++
        } else {
            cnt = 0
        }

        if ((cnt & 1) != 0 && ((mask & cnt) != 0)) {
            return true
        }
    }
    return false
}