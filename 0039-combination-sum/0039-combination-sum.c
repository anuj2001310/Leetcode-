/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

void backtrack(int* candidates, int candidatesSize, int target, int start,
               int* current_combination, int current_size, int** result,
               int* returnSize, int* returnColumnSizes) {
    // Base case: if target is 0, we have found a valid combination
    if (target == 0) {
        result[*returnSize] = (int*)malloc(current_size * sizeof(int));
        for (int i = 0; i < current_size; i++) {
            result[*returnSize][i] = current_combination[i];
        }
        returnColumnSizes[*returnSize] = current_size;
        (*returnSize)++;
        return;
    }

    // Explore all candidates starting from 'start'
    for (int i = start; i < candidatesSize; i++) {
        // If the current candidate is greater than the remaining target, skip it
        if (candidates[i] > target) 
            continue;

        // Add the current candidate to the combination
        current_combination[current_size] = candidates[i];

        // Recursively explore with the updated target and current combination
        backtrack(candidates, candidatesSize, target - candidates[i], i,
                current_combination, current_size + 1, result, returnSize,
                returnColumnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(150 * sizeof(int*)); // Assume there will be less than 150 combinations
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(150 * sizeof(int)); // To store the sizes of each combination

    int* current_combination = (int*)malloc(
        target * sizeof(int)); // Temporary array to store current combination

    backtrack(candidates, candidatesSize, target, 0, current_combination, 0, result, returnSize, *returnColumnSizes);

    free(current_combination);
    return result;
}

void printResult(int** result, int returnSize, int* returnColumnSizes) {
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
