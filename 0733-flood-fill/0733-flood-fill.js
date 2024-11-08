/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} color
 * @return {number[][]}
 */
var floodFill = function (image, sr, sc, color) {
    var n = image.length
    var m = image[0].length
    var ini = image[sr][sc]

    const ans = image
    const dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]

    const q = [[sr, sc]]
    ans[sr][sc] = color

    while (q.length != 0) {
        let arr = q.shift()
        let r = arr[0]
        let c = arr[1]

        for (let i = 0; i < dirs.length; ++i) {
            let nr = r + dirs[i][0]
            let nc = c + dirs[i][1]

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] === ini && ans[nr][nc] !== color) {
                q.push([nr, nc])
                ans[nr][nc] = color
            }
        }
    }
    
    return ans
};