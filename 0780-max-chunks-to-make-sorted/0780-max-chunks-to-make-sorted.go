func maxChunksToSorted(arr []int) int {
    cnt, maz := 0, -1
    for idx, ele := range arr {
        maz = max(maz, ele)

        if maz == idx {
            cnt++
        }
    }
    return cnt
}