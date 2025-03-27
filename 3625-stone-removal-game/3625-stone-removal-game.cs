public class Solution {
    public bool CanAliceWin(int n) {
        for (var i = 10; i >= 0; --i) {
            if (n < i)
                return (i & 1) != 0;
            n -= i;
        }
        return false;
    }
}