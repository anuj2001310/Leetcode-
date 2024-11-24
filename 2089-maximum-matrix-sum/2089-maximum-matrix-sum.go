func maxMatrixSum(matrix [][]int) int64 {
    cnt := 0
    min := math.MaxInt32
    var sum int64 = 0
    
    for _, row := range matrix {
        for _, ele := range row {
            if ele < 0 {
                cnt++
            }
            sum += int64(math.Abs(float64(ele))) 
            min = int(math.Min(float64(min), math.Abs(float64(ele))))
        }
    }
    
    if cnt % 2 != 0 {
        return sum - 2 * int64(min)
    }
    
    return sum
}