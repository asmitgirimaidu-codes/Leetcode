#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char* smallestSubsequence(char* s) {
    int n = strlen(s);
    int last_occurrence[26];
    bool in_stack[26] = {false};
    
    // Step 1: Record the last index of each character
    for (int i = 0; i < n; i++) {
        last_occurrence[s[i] - 'a'] = i;
    }
    
    char* stack = (char*)malloc((n + 1) * sizeof(char));
    int top = -1;
    
    // Step 2: Iterate through the string
    for (int i = 0; i < n; i++) {
        char c = s[i];
        
        // If character is already in stack, skip it
        if (in_stack[c - 'a']) continue;
        
        // Maintain monotonic property:
        // While stack not empty AND current char is smaller than top
        // AND top char appears again later in the string
        while (top >= 0 && c < stack[top] && i < last_occurrence[stack[top] - 'a']) {
            in_stack[stack[top] - 'a'] = false;
            top--;
        }
        
        // Push current char
        stack[++top] = c;
        in_stack[c - 'a'] = true;
    }
    
    stack[++top] = '\0'; // Null terminate the result
    return stack;
}