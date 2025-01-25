package main

import "sort"

type Pair struct {
    value int
    index int
}

func lexicographicallySmallestArray(nums []int, limit int) []int {
    n := len(nums)
    help := make([]Pair, n)

    for i := 0; i < n; i++ {
        help[i] = Pair{nums[i], i}
    }

    sort.Slice(help, func(i, j int) bool {
        return help[i].value < help[j].value
    })

    res := make([]int, n)
    pos := []int{}

    s, e := 0, 0
    for e < n {
        pos = append(pos, help[e].index)
        e++

        if e == n || help[e].value-help[e-1].value > limit {
            sort.Ints(pos)
            for _, idx := range pos {
                res[idx] = help[s].value
                s++
            }
            pos = []int{}
        }
    }

    return res
}
