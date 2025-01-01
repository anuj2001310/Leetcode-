func lemonadeChange(bills []int) bool {
    five, ten := 0, 0

    for _, bill := range bills {
        if bill == 5 {
            five++
        } else if bill == 10 {
            if five >= 1 {
                five--
                ten++
            } else {
                return false
            }
        } else {
            if five >= 1 && ten >= 1 {
                five--
                ten--
            } else if five >= 3 {
                five -= 3
            } else {
                return false
            }
        }
    }
    return true
}