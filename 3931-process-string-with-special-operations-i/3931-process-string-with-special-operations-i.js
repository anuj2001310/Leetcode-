/**
 * @param {string} s
 * @return {string}
 */
var processStr = function(s) {
    const stack = []
    let n = s.length;
    for (let i = 0; i < n; i++) {
        let ch = s[i];
        if (ch >= 'a' && ch <= 'z')  {
            stack.push(ch);
            continue;
        }
        if (ch == '*' && stack.length > 0)
            stack.pop();
        else if (ch == '#')
            stack.push(...stack);
        else if (ch == '%')
            stack.reverse();
    }
    return stack.join("");
};