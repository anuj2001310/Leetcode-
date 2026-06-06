func leftRightDifference(nums []int) []int {
	var lsum, rsum int
	for _, num := range nums {
		rsum += num
	}
	for i, num := range nums {
		rsum -= num
		nums[i] = abs(lsum - rsum)
		lsum += num
	}
	return nums
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}