/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solve = function (board) {
    for (let i = 0; i < board[0].length; i += 1) {
        paintBoard(0, i, board);
        paintBoard(board.length - 1, i, board);
    }
    for (let i = 0; i < board.length; i += 1) {
        paintBoard(i, 0, board);
        paintBoard(i, board[0].length - 1, board);
    }

    for (let i = 0; i < board.length; i += 1) {
        for (let j = 0; j < board[0].length; j += 1) {
            if (board[i][j] === "O") {
                board[i][j] = "X";
            } else if (board[i][j] === "Y") {
                board[i][j] = "O";
            }
        }
    }
    return board;
};

function paintBoard(x, y, board) {
    if (x < 0 || x === board.length || y < 0 || y === board[0].length || board[x][y] !== "O") {
        return;
    }
    board[x][y] = "Y";
    paintBoard(x, y - 1, board);
    paintBoard(x, y + 1, board);
    paintBoard(x + 1, y, board);
    paintBoard(x - 1, y, board);
}