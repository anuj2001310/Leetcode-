/**
 * @param {number[][]} edges
 * @return {number[]}
 */


var find = function (dsu, v) {
    if (dsu[v] === -1) 
        return v;
    dsu[v] = find(dsu, dsu[v]);
    return dsu[v];
}

var findRedundantConnection = function (edges) {
    const n = edges.length;
    const dsu = Array(n + 1).fill(-1);

    for (const edge of edges) {
        const parentX = find(dsu, edge[0]);
        const parentY = find(dsu, edge[1]);

        if (parentX === parentY) {
            return edge;
        } else {
            dsu[parentX] = parentY;
        }
    }

    return [0, 0];
};