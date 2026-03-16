function v(ch: string): boolean {
    let str: string = "aeiou";
    return str.includes(ch);
}

function trimTrailingVowels(s: string): string {
    let n: number = s.length;
    let id: number = n - 1;

    while (id >= 0) {
        if (!v(s[id]))
            break;
        id--;
    }
    return s.slice(0, id + 1);
};