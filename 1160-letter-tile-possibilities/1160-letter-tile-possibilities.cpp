class Solution {
public:
    void backtrack(unordered_map<char, int>& map, int& cnt) {
        for (auto& e : map) {
            if (e.second > 0) {
                e.second--;
                cnt++;
                backtrack(map, cnt);
                e.second++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> map;
        for (int i = 0; i < tiles.size(); i++)
            map[tiles[i]]++;
        int cnt = 0;
        backtrack(map, cnt);
        return cnt;
    }
};