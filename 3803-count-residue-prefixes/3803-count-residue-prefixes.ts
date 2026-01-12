/**
* Counts prefixes where:
*   number of distinct elements === (prefix length mod 3)
*/
function residuePrefixes<T>(sequence: Iterable<T>): number {
    const freq = new Map<T, number>();
    let distinct = 0;
    let index = 0;
    let answer = 0;

    for (const item of sequence) {
        index++;

        const count = freq.get(item) ?? 0;
        if (count === 0) {
            distinct++;
        }
        freq.set(item, count + 1);

        if (distinct === index % 3) {
            answer++;
        }
    }

    return answer;
};