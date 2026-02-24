/**
 * @param {number[]} bulbs
 * @return {number[]}
 */
var toggleLightBulbs = function(bulbs) {
    let n = bulbs.length;
    const map = new Array(101).fill(false);

    for (let i = 0; i < n; i++) {
        if (map[bulbs[i]])
            map[bulbs[i]] = false;
        else    
            map[bulbs[i]] = true;
    }
    const arr = []
    for (let i = 0; i < 101; i++) {
        if (map[i])
            arr.push(i);
    }

    return arr;
};