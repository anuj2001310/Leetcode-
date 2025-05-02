/**
 * @param {string} dominoes
 * @return {string}
 */
var pushDominoes = function (dominoes) {
    dominoes += 'R'
    let str = ''
    let dots = 0
    let last = 'L'
    for (let i = 0; i < dominoes.length; i++) {
        if (dominoes[i] === '.')
            dots++
        else if (dominoes[i] === 'L') {
            if (last === 'L')
                str += 'L'.repeat(dots)
            else if (last === 'R') {
                if ((dots & 1) === 0) {
                    str += 'R'.repeat(dots >> 1)
                    str += 'L'.repeat(dots >> 1)
                } else {
                    str += 'R'.repeat(Math.floor(dots >> 1))
                    str += '.'
                    str += 'L'.repeat(Math.floor(dots >> 1))
                }
            }
            str += 'L'
            last = 'L'
            dots = 0
        } 
        else if (dominoes[i] === 'R') {
            if (last === 'R')
                str += 'R'.repeat(dots) 
            else if (last === 'L')
                str += '.'.repeat(dots)

            str += 'R'
            last = 'R'
            dots = 0
        }

    }


    return str.slice(0, str.length - 1)
};