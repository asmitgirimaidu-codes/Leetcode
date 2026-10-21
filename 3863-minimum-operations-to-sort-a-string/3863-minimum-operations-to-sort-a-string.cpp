#include <string>
#include <algorithm>

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        
        // Check if the string is already sorted
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }
        
        // If the string length is 2 and not sorted, it's impossible to sort
        // because any proper substring has length 1 (which does nothing).
        if (n == 2) {
            return -1;
        }
        
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());
        
        // Check if minimum character is at the beginning (not the entire string)
        // or maximum character is at the end (not the entire string).
        bool min_at_start = (s[0] == mn);
        bool max_at_end = (s[n - 1] == mx);
        
        if (min_at_start || max_at_end) {
            return 1;
        }
        
        // If the only maximum character is at the start AND the only minimum character is at the end
        // It requires 3 operations.
        int min_count = count(s.begin(), s.end(), mn);
        int max_count = count(s.begin(), s.end(), mx);
        
        if (s[0] == mx && max_count == 1 && s[n - 1] == mn && min_count == 1) {
            return 3;
        }
        
        // Otherwise, 2 operations are sufficient.
        return 2;
    }
};