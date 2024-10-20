/**
 * @param {string} expression
 * @return {boolean}
 */
var parseBoolExpr = function (expression) {
    const stack = [];
    let i = 0;

    while (i < expression.length) {
        if (expression[i] === ')') {
            const subExpr = [];
            while (stack.length && stack[stack.length - 1] !== '(') {
                subExpr.push(stack.pop());
            }
            stack.pop(); // Remove '('
            const operator = stack.pop();
            let result;

            if (operator === '&') {
                result = subExpr.every(expr => expr === 't');
            } else if (operator === '|') {
                result = subExpr.some(expr => expr === 't');
            } else if (operator === '!') {
                result = subExpr[0] === 'f';
            }

            stack.push(result ? 't' : 'f');
        } else if (expression[i] !== ',') {
            stack.push(expression[i]);
        }
        i++;
    }

    return stack[0] === 't';
};