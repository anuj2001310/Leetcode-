function vowelConsonantScore(s: string): number {
    let str: string = "aeiou";
    let v: number = 0, c: number = 0;
    for (let ch of s) {
        if (str.includes(ch))
            v += 1
        else if (ch >= 'a' && ch <= 'z' && !str.includes(ch))
            c += 1

    }
    if (c == 0)
        return 0;
    return Math.floor(v / c);

};