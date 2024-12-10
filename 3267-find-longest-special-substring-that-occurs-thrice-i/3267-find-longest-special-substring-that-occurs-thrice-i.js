/**
 * @param {string} s
 * @return {number}
 */
var maximumLength = function (s) {
    let l = 1;
    let r = s.length;
    let max = -1;

    const hasSpecial = (s, windowLength) => {
        let l = 0;

        let count = 0;
        const map = new Map();

        for (let r = 0; r < s.length; r++) {
            if (r > 0 && s[r] !== s[r - 1]) {
                l = r;
            }

            if (r - l + 1 === windowLength) {
                map.set(s[r], (map.get(s[r]) || 0) + 1);

                if (map.get(s[r]) >= 3) {
                    return true;
                }

                l++;
            }
        }

        return false;
    }

    while (l <= r) {
        const mid = Math.floor((l + r) / 2);
        if (hasSpecial(s, mid)) {
            l = mid + 1;
            max = Math.max
        } else
            r = mid - 1;
    }

    return r === 0 ? -1 : r;
};