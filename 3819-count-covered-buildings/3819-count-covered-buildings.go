import (
    "fmt"
    "math"
)
func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}
func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
func countCoveredBuildings(n int, buildings [][]int) int {
    x_min, y_min := make([]int, n + 1), make([]int, n + 1)
    x_max, y_max := make([]int, n + 1), make([]int, n + 1)

    for i := 0; i < n + 1; i++ {
        x_min[i] = math.MaxInt
        y_min[i] = math.MaxInt
    }

    for i := 0; i < n + 1; i++ {
        x_max[i] = math.MinInt
        y_max[i] = math.MinInt
    }

    for _, building := range buildings {
        x := building[0]
        y := building[1]
        x_min[x] = min(x_min[x], y)
        x_max[x] = max(x_max[x], y)
        y_min[y] = min(y_min[y], x)
        y_max[y] = max(y_max[y], x)
    }
    
    cnt := 0
    for _, building := range buildings {
        x := building[0]
        y := building[1]
        if y > x_min[x] && y < x_max[x] && x > y_min[y] && x < y_max[y] {
            cnt++
        }
    }
    return cnt
}