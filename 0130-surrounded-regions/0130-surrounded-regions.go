func dfs(board [][]byte, i int, j int) {
    if board[i][j] != 'O' {
        return
    }

    board[i][j] = 'I'
    if i > 0 && board[i - 1][j] == 'O' {
        dfs(board, i - 1, j)
    }
    if i < len(board) - 1 && board[i + 1][j] == 'O' {
        dfs(board, i + 1, j)
    }
    if j > 0 && board[i][j - 1] == 'O' {
        dfs(board, i, j - 1)
    }
    if j < len(board[0]) - 1 && board[i][j + 1] == 'O' {
        dfs(board, i, j + 1)
    }
}

func solve(board [][]byte) {
    m := len(board)
    n := len(board[0])

    for i := 0; i < m; i++ {
        if i == 0 || i == m - 1 {
            for j := 0; j < n; j++ {
                dfs(board, i, j)
            }
        } else {
            dfs(board, i, 0)
            dfs(board, i, n - 1)
        }
    }

    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if board[i][j] == 'O' {
                board[i][j] = 'X'
            }                      
        }
    }

    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if board[i][j] == 'I' {
                board[i][j] = 'O'
            }                      
        }
    }
}