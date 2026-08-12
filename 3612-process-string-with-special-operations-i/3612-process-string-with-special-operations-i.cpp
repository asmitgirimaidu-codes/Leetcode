#include <string>
#include <algorithm>

class Solution {
public:
    std::string processStr(std::string s) {
        std::string result = "";
        
        for (char c : s) {
            if (c == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else if (c == '#') {
                result += result;
            } else if (c == '%') {
                std::reverse(result.begin(), result.end());
            } else {
                result.push_back(c);
            }
        }
        
        return result;
    }
};