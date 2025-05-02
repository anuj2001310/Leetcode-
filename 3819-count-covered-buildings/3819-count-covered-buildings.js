/**
 * @param {number} n
 * @param {number[][]} buildings
 * @return {number}
 */
var countCoveredBuildings = function(n, buildings) {
    const x_min = Array(n + 1).fill(Number.MAX_VALUE);
    const x_max = Array(n + 1).fill(Number.MIN_VALUE);
    
    const y_min = Array(n + 1).fill(Number.MAX_VALUE);
    const y_max = Array(n + 1).fill(Number.MIN_VALUE);
    
    for (let building of buildings) {
        let x = building[0], y = building[1];
        x_min[x] = Math.min(x_min[x], y);
        x_max[x] = Math.max(x_max[x], y);
        y_min[y] = Math.min(y_min[y], x);
        y_max[y] = Math.max(y_max[y], x);
    }

    let cnt = 0;
    for (let building of buildings) {
        let x = building[0];
        let y = building[1];
        if (y > x_min[x] && y < x_max[x] && x > y_min[y] && x < y_max[y])
            cnt++;
    }
    
    return cnt;
};