function countOddLetters(n: number): number {
    const arr: string[] = [
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
    ]

    let freq: number[] = new Array(26).fill(0);

    for (; n > 0;) {
        let r: number = n % 10;

        for (let ch of arr[r]) {
            let id: number = ch.charCodeAt(0) - 97;
            freq[id]++;
        }

        n = Math.floor(n / 10);
    }

    let cnt: number = 0;

    for (let i: number = 0; i < 26; i++) {
        if (freq[i] == 0)
            continue;
            
        cnt += ((freq[i] & 1) > 0 ? 1 : 0);
    }
    return cnt;
};