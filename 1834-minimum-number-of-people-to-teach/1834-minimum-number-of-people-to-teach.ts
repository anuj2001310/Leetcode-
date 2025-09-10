function minimumTeachings(n: number, languages: number[][], friendships: number[][]): number {
    const ex: Set<number> = new Set();
    for (const f of friendships) {
        const hash: Set<number> = new Set();
        let c: boolean = false;
        for (const l of languages[f[0] - 1])
            hash.add(l);
        
        for (const l of languages[f[1] - 1]) {
            if (hash.has(l)) {
                c = true;
                break;
            }
        }

        if (!c) {
            ex.add(f[0] - 1);
            ex.add(f[1] - 1);
        }
    }
    let ans: number = 0;
    const cnt: Array<number> = new Array(n + 1).fill(0);
    for (const p of ex) {
        for (const l of languages[p]) {
            cnt[l]++;
            ans = Math.max(ans, cnt[l]);
        }
    }
    return ex.size - ans;
};