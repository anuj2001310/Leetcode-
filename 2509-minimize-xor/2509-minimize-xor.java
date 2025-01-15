class Solution {
    public int minimizeXor(int num1, int num2) {
        int bc = Integer.bitCount(num2);
        bc -= Integer.bitCount(num1);

        int cur = 1;
        while (bc != 0) {
            if (bc < 0 && (num1 & cur) != 0) {
                num1 ^= cur;
                bc++;
            }
            else if (bc > 0 && (num1 & cur) == 0) {
                num1 |= cur;
                bc--;
            }
            cur <<= 1;
        }
        return num1;
    }
}