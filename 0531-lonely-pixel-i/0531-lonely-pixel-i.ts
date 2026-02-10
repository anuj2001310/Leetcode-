function findLonelyPixel(p: string[][]): number {
    let n: number = p.length, m: number = p[0].length;
    const rows = new Array(n).fill(0);
    const cols = new Array(m).fill(0);

    for (let i: number = 0; i < n; ++i) {
        for (let j: number = 0; j < m; ++j) {
            if (p[i][j] == 'B') {
                rows[i]++;
                cols[j]++;
            }
        }
    }

    let c: number = 0;
    for (let i: number = 0; i < n; i++) {
        for (let j: number = 0; j < m; ++j) {
            if (p[i][j] == 'B' && rows[i] == 1 && cols[j] == 1)
                c++;
        }
    }
    return c;
};