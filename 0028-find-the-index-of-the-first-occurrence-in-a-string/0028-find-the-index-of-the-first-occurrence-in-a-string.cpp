class Solution {
public:
    int strStr(string haystack, string needle) {
        int hLen = haystack.length();
        int nLen = needle.length();
        
        // If the needle is longer than the haystack, it's impossible to find a match
        if (nLen > hLen) {
            return -1;
        }
        
        // Iterate through the haystack just enough times to fit the needle
        for (int i = 0; i <= hLen - nLen; ++i) {
            int j = 0;
            
            // Check if the characters match one by one
            while (j < nLen && haystack[i + j] == needle[j]) {
                j++;
            }
            
            // If j reached the length of the needle, we found a full match
            if (j == nLen) {
                return i;
            }
        }
        
        // If the loop finishes without returning, the needle is not in the haystack
        return -1;
    }
};