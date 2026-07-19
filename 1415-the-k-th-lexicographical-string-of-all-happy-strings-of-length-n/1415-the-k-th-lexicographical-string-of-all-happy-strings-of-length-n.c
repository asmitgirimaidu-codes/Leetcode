#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void findKth(int n, int k, int *count, char *current, int index, char *result) {
    if (index == n) {
        (*count)++;
        if (*count == k) {
            strcpy(result, current);
        }
        return;
    }

    for (char c = 'a'; c <= 'c'; c++) {
        if (index > 0 && current[index - 1] == c) {
            continue;
        }
        current[index] = c;
        findKth(n, k, count, current, index + 1, result);
        if (result[0] != '\0') return; // Found the kth string
    }
}

char* getHappyString(int n, int k) {
    int count = 0;
    char *result = (char *)calloc(n + 1, sizeof(char));
    char *current = (char *)malloc((n + 1) * sizeof(char));
    current[n] = '\0';
    
    findKth(n, k, &count, current, 0, result);
    
    free(current);
    return result;
}