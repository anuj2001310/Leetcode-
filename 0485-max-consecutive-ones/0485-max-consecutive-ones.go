func findMaxConsecutiveOnes(nums []int) int {
	maxi := 0
	temp := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] == 1 {
			temp++
			maxi = max(maxi, temp)
		} else {
			temp = 0
		}
	}
	return maxi
}