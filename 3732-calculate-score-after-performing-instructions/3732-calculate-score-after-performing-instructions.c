long long calculateScore(char** instructions, int n, int* values, int v) {
    bool* vis = (bool*)calloc(sizeof(bool), n);
    int i = 0;
    long long score = 0;
    for (; i >= 0 && i < n && !vis[i]; ) {
        vis[i] = true;
        char curr = instructions[i][0];
        switch(curr) {
            case 'a':
                score += values[i];
                i++;
                break;
            default:
                i += values[i];
                break;
        }
    }
    return score;
}