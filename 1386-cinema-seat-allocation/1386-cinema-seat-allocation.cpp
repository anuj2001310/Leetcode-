class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> blockSeatCount;
        for (int i = 0; i < reservedSeats.size(); i++) {
            if (reservedSeats[i][1] >= 2 && reservedSeats[i][1] <= 9)
                blockSeatCount[reservedSeats[i][0]].insert(reservedSeats[i][1]);
        }
        int assignGroups = 0;
        int totalUsedRow = 0;
        for (auto& i : blockSeatCount) {
            totalUsedRow++;
            bool left = true, middle = true, right = true;
            for (int seat = 2; seat <= 5; seat++)
                if (i.second.count(seat))
                    left = false;

            for (int seat = 4; seat <= 7; seat++)
                if (i.second.count(seat))
                    middle = false;

            for (int seat = 6; seat <= 9; seat++)
                if (i.second.count(seat))
                    right = false;

            if (left || middle || right)
                assignGroups++;
        }
        int leftRow = n - totalUsedRow;
        assignGroups += leftRow * 2;
        return assignGroups;
    }
};