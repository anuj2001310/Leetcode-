func findTheDistanceValue(arr1 []int, arr2 []int, d int) int {
	sort.Ints(arr2)
	cnt := 0

	for _, x := range arr1 {
		p := sort.SearchInts(arr2, x)

		ok := true
		if p < len(arr2) {
			ok = ok && (arr2[p]-x > d)
		}
		if p-1 >= 0 && p-1 < len(arr2) {
			ok = ok && (x-arr2[p-1] > d)
		}

		if ok {
			cnt++
		}
	}
	return cnt
}