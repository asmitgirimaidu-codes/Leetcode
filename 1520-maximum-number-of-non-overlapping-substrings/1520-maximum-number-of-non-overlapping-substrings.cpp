#include <vector>
#include <string>
#include <algorithm>
#include <climits>

class Solution {
public:
    std::vector<std::string> maxNumOfSubstrings(std::string s) {
        int n = s.length();
        std::vector<int> first(26, -1), last(26, -1);
        
        // Step 1: Find the first and last occurrences of each character
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (first[c] == -1) {
                first[c] = i;
            }
            last[c] = i;
        }
        
        // Step 2: Find valid substrings for each character by expanding bounds
        std::vector<std::pair<int, int>> intervals;
        
        for (int i = 0; i < 26; ++i) {
            if (first[i] == -1) continue;
            
            int left = first[i];
            int right = last[i];
            bool valid = true;
            
            // Expand the substring to include all occurrences of any character within the range
            for (int j = left; j <= right; ++j) {
                int c = s[j] - 'a';
                if (first[c] < left) {
                    // If a character's first occurrence is outside to the left, 
                    // this starting character cannot form a valid isolated substring.
                    valid = false;
                    break;
                }
                right = std::max(right, last[c]);
            }
            
            if (valid) {
                intervals.push_back({left, right});
            }
        }
        
        // Step 3: Sort intervals by their end index (Greedy approach)
        std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });
        
        // Step 4: Select non-overlapping intervals with minimum total length
        std::vector<std::string> result;
        int last_end = -1;
        
        for (const auto& interval : intervals) {
            if (interval.first > last_end) {
                result.push_back(s.substr(interval.first, interval.second - interval.first + 1));
                last_end = interval.second;
            }
        }
        
        return result;
    }
};