class Solution {
    public int countOdds(int l, int h) {
        if ((l & 1) != 0 && (h & 1) != 0)
            return ((h - l) >> 1) + 1;
        
        else if ((l & 1) == 0 && (h & 1) == 0)
            return ((h - l) >> 1);
        
        return ((h - l) >> 1) + 1;
    }
}