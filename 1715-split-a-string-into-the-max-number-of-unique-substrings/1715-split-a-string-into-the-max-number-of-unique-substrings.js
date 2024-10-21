/**
 * @param {string} s
 * @return {number}
 */
var maxUniqueSplit = function (s) {
    const set = new Set();

    const traverse = (s, start, set) => {
        if (start === s.length)
            return 0;
        let max = 0;
        for (let i = start + 1; i <= s.length; i++) {
            let substr = s.substring(start, i);
            if (set.has(substr))
                continue;
            if (max >= set.size + s.length - start)
                continue;
    
            set.add(substr);
            max = Math.max(max, 1 + traverse(s, i, set))
            set.delete(substr);
        }
        return max;
    }

    return traverse(s, 0, set)
};