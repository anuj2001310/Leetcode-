package main

import "math"

func maxScoreSightseeingPair(values []int) int {
    ans := math.MinInt32
    ind := 0
    
    for i := 1; i < len(values); i++ {
        ans = int(math.Max(float64(ans), float64(values[ind] + values[i] - (i - ind))))
        
        if values[i] + i > values[ind] + ind {
            ind = i
        }
    }
    return ans
}
