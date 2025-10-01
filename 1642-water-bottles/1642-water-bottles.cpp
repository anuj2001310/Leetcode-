class Solution {
public:
    int numWaterBottles(int b, int e) {
       return (b * e - 1) / (e - 1); 
    }
};