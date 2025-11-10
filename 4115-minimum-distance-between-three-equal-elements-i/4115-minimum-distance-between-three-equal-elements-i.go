func minimumDistance(nums []int) int {
    unordered_map := make(map[int][]int)

    for i, num := range nums {
        unordered_map[num] = append(unordered_map[num], i)
    }

    ans := math.MaxInt
    for _, val := range unordered_map {
        if len(val) < 3 {
            continue
        }
        
        for j := 0; j + 2 < len(val); j++ {
            a, b, c := val[j], val[j + 1], val[j + 2]
			temp := abs(a - b) + abs(b - c) + abs(c - a)
			if temp < ans {
				ans = temp
			}
        }
    }
    if ans == math.MaxInt {
		return -1
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}