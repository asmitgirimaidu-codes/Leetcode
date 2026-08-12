#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<int> separateDigits(std::vector<int>& nums) {
        std::vector<int> result;
        for (int num : nums) {
            std::string s = std::to_string(num);
            for (char c : s) {
                result.push_back(c - '0');
            }
        }
        return result;
    }
};
