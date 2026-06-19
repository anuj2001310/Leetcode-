function largestAltitude(gain: number[]): number {
    let curr: number = 0;
    let max: number = 0;

    for (let g of gain) {
        curr += g;
        max = Math.max(max, curr);
    }
    return max;
};