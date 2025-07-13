class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int i = 0, j = 0, cnt = 0;
        sort(begin(players), end(players));
        sort(begin(trainers), end(trainers));

        while (j < trainers.size() && i < players.size()) {
            if (players[i] <= trainers[j]) {
                i++;
                cnt++;
            }
            j++;
        }
        return cnt;
    }
};