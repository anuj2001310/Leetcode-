int idx(int r, int c) { 
    return r * 3 + c;
}

inline int setb(int val, int b, int bit_val) {
    if (((val >> b) & 1) != bit_val)
        return val ^ (1 << b);
    else 
        return val;
}
int set_b(int board, int idx, int val) {
    board = setb(board, idx * 3, val & 1);
    board = setb(board, idx * 3 + 1, (val >> 1) & 1);
    board = setb(board, idx * 3 + 2, (val >> 2) & 1);
    return board;
}

int get(int board, int idx) {
    int val = 0;
    val = (val << 1) | ((board >> (idx * 3 + 2)) & 1);
    val = (val << 1) | ((board >> (idx * 3 + 1)) & 1);
    val = (val << 1) | ((board >> (idx * 3)) & 1);

    return val;
}

map<int, int> dist;
bool bfs_done = false;
void bfs() {
    if (bfs_done)
        return;
    else
        bfs_done = true;

    queue<int> q;

    int b = 0;
    b = set_b(b, 0, 1);
    b = set_b(b, 1, 2);
    b = set_b(b, 2, 3);
    b = set_b(b, 3, 4);
    b = set_b(b, 4, 5);
    b = set_b(b, 5, 0);

    q.push(b);
    dist[b] = 0;
    while (q.size() > 0) {
        b = q.front();
        q.pop();
        int d = dist[b];

        for (int r = 0; r <= 1; r++)
            for (int c = 0; c <= 2; c++)
                if (get(b, idx(r, c)) == 0) {
                    for (int dx = -1; dx <= 1; dx++)
                        for (int dy = -1; dy <= 1; dy++)
                            if (abs(dy) + abs(dx) == 1) {
                                int x = r + dx, y = c + dy;
                                if (0 <= x && x <= 1 && 0 <= y && y <= 2) {
                                    int valxy = get(b, idx(x, y));
                                    int newb = set_b(b, idx(r, c), valxy);
                                    newb = set_b(newb, idx(x, y), 0);
                                    
                                    auto itr = dist.find(newb);
                                    if (itr == dist.end()) {
                                        dist[newb] = d + 1;
                                        q.push(newb);
                                    }
                                }
                            }
                }
    }
}

class Solution {

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        bfs();
        int curb = 0;
        for (int r = 0; r <= 1; r++)
            for (int c = 0; c <= 2; c++) {
                curb = set_b(curb, idx(r, c), board[r][c]);
            }

        auto itr = dist.find(curb);
        if (itr == dist.end())
            return -1;
        else
            return itr->second;
    }
};