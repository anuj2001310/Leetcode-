function digitFrequencyScore(n: number): number {
    let sum : number = 0;
    while (n != 0) {
        sum += (n % 10);
        n = Math.floor(n / 10);
    }
    return sum;
};