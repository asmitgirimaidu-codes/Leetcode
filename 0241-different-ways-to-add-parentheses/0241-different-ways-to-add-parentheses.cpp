#include <vector>
#include <string>
#include <unordered_map>

class Solution {
private:
    std::unordered_map<std::string, std::vector<int>> memo;

public:
    std::vector<int> diffWaysToCompute(std::string expression) {
        // If result is already computed, return it from memo
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }

        std::vector<int> results;
        int n = expression.length();

        for (int i = 0; i < n; ++i) {
            char c = expression[i];
            // If the character is an operator, split the expression
            if (c == '+' || c == '-' || c == '*') {
                std::string leftExpr = expression.substr(0, i);
                std::string rightExpr = expression.substr(i + 1);

                std::vector<int> leftResults = diffWaysToCompute(leftExpr);
                std::vector<int> rightResults = diffWaysToCompute(rightExpr);

                // Combine results from left and right sub-expressions
                for (int leftVal : leftResults) {
                    for (int rightVal : rightResults) {
                        if (c == '+') {
                            results.push_back(leftVal + rightVal);
                        } else if (c == '-') {
                            results.push_back(leftVal - rightVal);
                        } else if (c == '*') {
                            results.push_back(leftVal * rightVal);
                        }
                    }
                }
            }
        }

        // Base case: if no operators were found, the string is just a number
        if (results.empty()) {
            results.push_back(std::stoi(expression));
        }

        return memo[expression] = results;
    }
};