#include <stdlib.h>

// Comparison function for qsort (descending order)
int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    int maxArea = 0;

    // Use the first row as the base, or create a heights array
    // Here we modify the matrix in-place to store heights
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                matrix[i][j] += matrix[i - 1][j];
            }
        }
    }

    // For each row, sort heights and calculate potential max area
    for (int i = 0; i < m; i++) {
        qsort(matrix[i], n, sizeof(int), compare);
        for (int j = 0; j < n; j++) {
            int height = matrix[i][j];
            int area = height * (j + 1);
            if (area > maxArea) {
                maxArea = area;
            }
        }
    }

    return maxArea;
}