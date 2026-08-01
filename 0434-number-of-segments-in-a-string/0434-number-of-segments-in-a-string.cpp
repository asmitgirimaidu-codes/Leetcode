#include <string>

class Solution {
public:
    int countSegments(std::string s) {
        int segmentCount = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            // A segment starts if the current character is not a space
            // and the previous character was a space (or it's the first character)
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
                segmentCount++;
            }
        }
        
        return segmentCount;
    }
};