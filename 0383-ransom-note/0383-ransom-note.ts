function canConstruct(ransomNote: string, magazine: string): boolean {
    let freq: Array<number> = new Array(26).fill(0);
    let n: number = magazine.length;
    let m: number = ransomNote.length;
    
    for (let i: number = 0; i < n; i++)
        freq[magazine.charCodeAt(i) - 97]++;

    for (let i: number = 0; i < m; i++) {
        let id: any = ransomNote.charCodeAt(i) - 97;
        if (--freq[id] == -1)
            return false;
    }
    return true;
};