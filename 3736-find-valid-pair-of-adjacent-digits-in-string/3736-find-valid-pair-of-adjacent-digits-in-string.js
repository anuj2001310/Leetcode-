/**
 * @param {string} s
 * @return {string}
 */
var findValidPair = function(s) {
    let n = s.length;
    const arr = Array(10).fill(0);
    for (let i = 0; i < n; i++) {
        let idx = s.charCodeAt(i) - 48;
        arr[idx]++;
    }
    //console.log(arr);
    for (let i = 1; i < n; i++) {
        let pre = s.charCodeAt(i - 1) - 48;
        let cur = s.charCodeAt(i) - 48;
        if (arr[pre] == pre && arr[cur] == cur && pre != cur)
            return "" + s[i - 1] + s[i];
    }
    return ""
};