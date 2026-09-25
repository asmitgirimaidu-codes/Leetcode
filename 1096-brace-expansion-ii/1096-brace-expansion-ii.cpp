#include <vector>
#include <string>
#include <set>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> braceExpansionII(std::string expression) {
        std::set<std::string> result_set = parse(expression);
        return std::vector<std::string>(result_set.begin(), result_set.end());
    }

private:
    std::set<std::string> parse(const std::string& expr) {
        int n = expr.length();
        int j = 0;
        std::set<std::string> current_group;
        current_group.insert(""); // Start with an empty string for concatenation
        
        std::vector<std::set<std::string>> terms;
        
        while (j < n) {
            if (expr[j] == '{') {
                // Find the matching closing brace
                int open_brackets = 0, start = j;
                while (j < n) {
                    if (expr[j] == '{') open_brackets++;
                    else if (expr[j] == '}') open_brackets--;
                    if (open_brackets == 0) break;
                    j++;
                }
                // Parse the inner expression recursively
                std::set<std::string> inner = parse(expr.substr(start + 1, j - start - 1));
                current_group = multiply(current_group, inner);
            } else if (expr[j] == ',') {
                // Comma separates groups (union), push current group to terms and reset
                for (const auto& s : current_group) {
                    terms.push_back({s});
                }
                current_group = {""};
            } else {
                // Single letter or character sequence
                std::string word = "";
                while (j < n && isalpha(expr[j])) {
                    word += expr[j];
                    j++;
                }
                j--; // Step back as the outer loop increments j
                std::set<std::string> letter_set = {word};
                current_group = multiply(current_group, letter_set);
            }
            j++;
        }
        
        for (const auto& s : current_group) {
            terms.push_back({s});
        }
        
        std::set<std::string> final_result;
        for (const auto& term : terms) {
            for (const auto& s : term) {
                final_result.insert(s);
            }
        }
        return final_result;
    }
    
    std::set<std::string> multiply(const std::set<std::string>& set1, const std::set<std::string>& set2) {
        std::set<std::string> result;
        for (const auto& s1 : set1) {
            for (const auto& s2 : set2) {
                result.insert(s1 + s2);
            }
        }
        return result;
    }
};