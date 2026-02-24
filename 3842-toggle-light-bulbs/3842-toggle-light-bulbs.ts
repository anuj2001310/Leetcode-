function toggleLightBulbs(bulbs: number[]): number[] {
    let n: number = bulbs.length;
    const map: boolean[] = new Array(101).fill(false);

    for (let i: number = 0; i < n; i++) {
        if (map[bulbs[i]])
            map[bulbs[i]] = false;
        else    
            map[bulbs[i]] = true;
    }
    const arr: number[] = []
    for (let i: number = 0; i < 101; i++) {
        if (map[i])
            arr.push(i);
    }

    return arr;
};