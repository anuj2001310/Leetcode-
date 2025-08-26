class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area = 0, bestDiag = 0;
        for (auto& d : dimensions) {
            int l = d[0], w = d[1];
            int diag = l * l + w * w;
            if (diag > bestDiag || (diag == bestDiag && l * w > area)) {
                area = l * w;
                bestDiag = diag;
            }
        }
        return area;
    }
};