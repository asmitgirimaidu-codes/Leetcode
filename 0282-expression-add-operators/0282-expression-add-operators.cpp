#include <string>
#include <vector>

class Solution {
private:
    void backtrack(const std::string& num, int target, int index, long long current_eval, long long prev_operand, std::string path, std::vector<std::string>& result) {
        if (index == num.length()) {
            if (current_eval == target) {
                result.push_back(path);
            }
            return;
        }

        for (int i = index; i < num.length(); ++i) {
            // Numbers cannot have leading zeros (e.g., "05" is invalid)
            if (i > index && num[index] == '0') {
                break;
            }

            std::string subStr = num.substr(index, i - index + 1);
            long long current_num = std::stoll(subStr);

            if (index == 0) {
                backtrack(num, target, i + 1, current_num, current_num, subStr, result);
            } else {
                backtrack(num, target, i + 1, current_eval + current_num, current_num, path + "+" + subStr, result);
                backtrack(num, target, i + 1, current_eval - current_num, -current_num, path + "-" + subStr, result);
                backtrack(num, target, i + 1, current_eval - prev_operand + prev_operand * current_num, prev_operand * current_num, path + "*" + subStr, result);
            }
        }
    }

public:
    std::vector<std::string> addOperators(std::string num, int target) {
        std::vector<std::string> result;
        if (num.empty()) return result;
        backtrack(num, target, 0, 0, 0, "", result);
        return result;
    }
};