function shortestDistance(words: string[], word1: string, word2: string): number {
    let minDistance = words.length;

    let word1LastIndex = -1;
    let word2LastIndex = -1;
    for (let i = 0; i < words.length; i++) {
        const word = words[i];

        if (word === word1) {
            word1LastIndex = i;
        } else if (word === word2) {
            word2LastIndex = i;
        }

        if (word1LastIndex >= 0 && word2LastIndex >= 0) {
            minDistance = Math.min(minDistance, Math.abs(word1LastIndex - word2LastIndex));
        }
    }

    return minDistance;
};