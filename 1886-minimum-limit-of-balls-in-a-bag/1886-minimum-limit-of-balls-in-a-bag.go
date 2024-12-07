func minimumSize(nums []int, maxOperations int) int {
    l, r := 1, 0
    maximum_num := func (x, y int) int { 
        if x > y { 
            return x;
        }; 
        return y; 
    }

    for _, num := range nums {
        r = maximum_num(r, num)
    }

    solve := func(nums []int, cost int, maxOperations int) bool {
        cnt := 0
        for _, v := range nums {
            cnt += (v - 1) / cost
            if cnt > maxOperations { 
                return false
            }
        }
        return true
    }
    for l <= r {
        m := (l + r) >> 1
        if solve(nums, m, maxOperations) {
            r = m - 1
        } else {
            l = m + 1
        }
    }
    return l
}