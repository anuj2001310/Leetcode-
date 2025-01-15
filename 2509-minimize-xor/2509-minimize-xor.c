int bits(int num) {
    int b = 0;
    while (num) {
        b++;
        num &= (num - 1);
    }
    return b;
}
int minimizeXor(int num1, int num2) {
    int setBitsNum2 = bits(num2);
    int result = 0;

    for (int i = 30; i >= 0 && setBitsNum2 > 0; i--) {
        if ((num1 & (1 << i)) != 0) {
            result |= (1 << i);
            setBitsNum2--;
        }
    }

    for (int i = 0; i <= 31 && setBitsNum2 > 0; i++) {
        if ((result & (1 << i)) == 0) {
            result |= (1 << i);
            setBitsNum2--;
        }
    }

    return result;
}