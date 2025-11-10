#include<stdio.h>
#include<stdlib.h>
//using namespace std;
//@# This solution is designed by Akshay Bhati


typedef struct {
    int* arr;
    int size;
} unordered_map;

void init(unordered_map* map) {
    for (int i = 0; i < 101; ++i) {
        map[i].size = 0;
        map[i].arr = (int*)calloc(101, sizeof(int));
    }
}

int minimumDistance(int* nums, int numsSize) {
    int ans = INT_MAX;
    unordered_map map[101];
    init(map);

    for (int i = 0; i < numsSize; ++i) {
        int key = nums[i];
        if (key < 0 || key >= 101) 
            continue;
        map[key].arr[map[key].size++] = i;
    }

    
    for (int i = 0; i < 101; ++i) {
        if (map[i].size < 3) 
            continue;

        for (int j = 0; j < map[i].size - 2; j++) {
            int a = map[i].arr[j];
            int b = map[i].arr[j + 1];
            int c = map[i].arr[j + 2];
            int temp = abs(a - b) + abs(b - c) + abs(c - a);
            if (temp < ans) 
                ans = temp;
        }
    }

    for (int i = 0; i < 101; ++i)
        free(map[i].arr);

    return ans == INT_MAX ? -1 : ans;
}
