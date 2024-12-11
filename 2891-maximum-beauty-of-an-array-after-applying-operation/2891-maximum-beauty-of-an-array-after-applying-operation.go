func maximumBeauty(nums []int, k int) int {
    freq := make([]int, 100001)

    xMax, xMin := 0, 1000000
    for _, num := range nums {
        freq[num]++
        xMax = max(num, xMax)
        xMin = min(num, xMin)
    }

    cnt, mxcnt := 0, 0
    r := xMin
    for l := xMin; r <= xMax; r++ {
        cnt += freq[r]
        for r - l > 2 * k {
            cnt -= freq[l]
            l++
        }
        mxcnt = max(mxcnt, cnt)
    }
    return mxcnt
}