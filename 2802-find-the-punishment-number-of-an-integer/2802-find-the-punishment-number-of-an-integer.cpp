class Solution {
public:
    bool CanPartition(int num, int target) {
        // Invalid partition found
        if (target < 0 || num < target)
            return false;

        if (num == target)
            return true;

        return CanPartition(num / 10, target - num % 10) or
               CanPartition(num / 100, target - num % 100) or
               CanPartition(num / 1000, target - num % 1000);
    }

    int punishmentNumber(int n) {
        int punishmentNum = 0;

        for (int currentNum = 1; currentNum <= n; currentNum++) {
            int squareNum = currentNum * currentNum;

            if (CanPartition(squareNum, currentNum))
                punishmentNum += squareNum;
        }
        return punishmentNum;
    }
};