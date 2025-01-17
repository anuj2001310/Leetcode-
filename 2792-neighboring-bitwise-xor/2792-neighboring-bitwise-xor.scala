object Solution {
    def doesValidArrayExist(derived: Array[Int]): Boolean = {
        var ans = 0
        for (x <- derived) {
           ans ^= x  // XOR assignment
        }     
        ans == 0
    }
}