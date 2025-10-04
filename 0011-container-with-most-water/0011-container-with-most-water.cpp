class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = INT_MIN;
        int size = height.size();
        // Take 1 pointer on start and  1 on last index
        int left = 0;
        int right = size - 1;
        // move pointers towards until they reach on middle
        while (left < right) {
            // Caculate the width of two numbers
            int width = right - left;
            // Calculate the height between these two pointers
            int h = min(height[left], height[right]);
            // The maximum water these two pointers can hold is this
            int water = width * h;
            // Now update the maxWater with the water between each 2 pointers
            maxWater = max(maxWater, water);
            // move the pointers towards each other
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxWater;
    }
};