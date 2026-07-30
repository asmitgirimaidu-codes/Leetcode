#include <string>
#include <algorithm>

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::string stack = "";
        
        for (char digit : num) {
            // Maintain a monotonic increasing stack: remove larger preceding digits
            while (!stack.empty() && stack.back() > digit && k > 0) {
                stack.pop_back();
                k--;
            }
            stack.push_back(digit);
        }
        
        // If k is still greater than 0, remove from the end
        while (k > 0 && !stack.empty()) {
            stack.pop_back();
            k--;
        }
        
        // Remove leading zeros
        int non_zero_idx = 0;
        while (non_zero_idx < stack.length() && stack[non_zero_idx] == '0') {
            non_zero_idx++;
        }
        
        std::string result = stack.substr(non_zero_idx);
        return result.empty() ? "0" : result;
    }
};