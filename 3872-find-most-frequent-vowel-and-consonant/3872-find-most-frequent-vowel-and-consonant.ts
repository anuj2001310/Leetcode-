function maxFreqSum(s: string): number {
    const freq = Array(26).fill(0);
    let n = s.length;

    let c = 0, v = 0;
    for (let i = 0; i < n; ++i) {
        let idx = s.charCodeAt(i) - 97;
        freq[idx]++;
    }
    
    const isVowel = (ch) => {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    for (let i = 0; i < n; ++i) {
        let idx = s.charCodeAt(i) - 97;
        if (isVowel(s[i]))
            v = (freq[idx] > v ? freq[idx] : v);
        else
            c = (freq[idx] > c ? freq[idx] : c);
    }
        
    return c + v;
};