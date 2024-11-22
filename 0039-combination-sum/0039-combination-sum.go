func find(idx int, arr []int, tar int, ans *[][]int, ds *[]int) {
    if tar == 0 {
        combination := make([]int, len(*ds))
        copy(combination, *ds)
        *ans = append(*ans, combination)
        return
    }
    
    if idx == len(arr) {
        return
    }

    if arr[idx] <= tar {
        *ds = append(*ds, arr[idx])
        find(idx, arr, tar - arr[idx], ans, ds)
        *ds = (*ds) [ : len(*ds) - 1]
    }

    find(idx + 1, arr, tar, ans, ds)
}

func combinationSum(candidates []int, target int) [][]int {
    ans := make([][]int, 0)
    ds := make([]int, 0)

    find(0, candidates, target, &ans, &ds)
    return ans
}