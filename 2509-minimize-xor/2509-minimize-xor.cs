public class Solution {
    public int MinimizeXor(int num1, int num2) {
        int bot(int num) {
            var bit = 0;
            while (num != 0) {
                num &= (num - 1);
                bit++;
            }
            return bit;
        }

        var bc = bot(num2);
        bc -= bot(num1);
        var c  = 1;
        while (bc != 0) {
            if (bc < 0 && (num1 & c) != 0) {
                num1 ^= c;
                bc++;
            }
            else if (bc > 0 && (num1 & c) == 0) {
                num1 |= c;
                bc--;
            }
            c <<= 1;
        }
        return num1;
    }
}