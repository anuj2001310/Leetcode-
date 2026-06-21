function maxIceCream(costs: number[], coins: number): number {
    let n: number = costs.length;
    let ct: number = 0;
    costs.sort((a, b) => {
        return a - b;
    });
    for (let i: number = 0; i < n; i++) {
        let diff: number = coins - costs[i];
        if (diff < 0)
            break;

        coins -= costs[i];
        ct++;
    }
    return ct;
};