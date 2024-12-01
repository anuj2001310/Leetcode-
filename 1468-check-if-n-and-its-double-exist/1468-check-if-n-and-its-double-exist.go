func checkIfExist(arr []int) bool {
	m := make(map[int]struct{})

	for i := 0; i < len(arr); i++ {
		if arr[i] & 1 == 0 {
			if _, ok := m[arr[i]  >> 1]; ok {
				return true
			}
		}

		if _, ok := m[arr[i] << 1]; ok {
			return true
		}

		m[arr[i]] = struct{}{}
	}

	return false
}