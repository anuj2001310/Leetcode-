func triangleType(nums []int) string {
    a, b, c := nums[0], nums[1], nums[2]
    if a == b && b == c {
        return "equilateral" 
    }
    if (a == b && a + b > c) || (b == c && b + c > a) || (a == c && a + c > b) {
        return "isosceles"
    }
    if a + b > c && b + c > a && a + c > b {
        return "scalene"
    }
    return "none"
}