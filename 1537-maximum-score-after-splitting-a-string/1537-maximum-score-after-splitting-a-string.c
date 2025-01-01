int maxScore(char* s) {
    int ones = 0, tempScore = s[0] == '0' ? 1 : 0;
    int score = tempScore;
    for (int i = 1; i < strlen(s) - 1; ++i) {
        if (s[i] == '0')
            tempScore++;
        else {
            ones++;
            tempScore--;
        }
        if (tempScore > score)
            score = tempScore;
    }
    ones += (s[strlen(s) - 1] == '1' ? 1 : 0);
    return ones + score;
}