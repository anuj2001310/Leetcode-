/**
 * @param {number} num1
 * @param {number} num2
 * @return {number}
 */
var minimizeXor = function(num1, num2) {
    const func = (num) => {
        let n = 0;
        while (num != 0) {
            n++;
            num &= (num - 1);
        }
        return n;
    }

    let bc = func(num2);
    bc -= func(num1);
    let c = 1;
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
};