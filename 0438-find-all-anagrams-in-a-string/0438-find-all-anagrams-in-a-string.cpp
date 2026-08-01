#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> result;
        if (s.length() < p.length()) {
            return result;
        }
        
        std::vector<int> pCount(26, 0);
        std::vector<int> sCount(26, 0);
        
        for (char c : p) {
            pCount[c - 'a']++;
        }
        
        int windowSize = p.length();
        
        for (int i = 0; i < s.length(); ++i) {
            sCount[s[i] - 'a']++;
            
            // Remove the character going out of the left of the window
            if (i >= windowSize) {
                sCount[s[i - windowSize] - 'a']--;
            }
            
            // Compare window frequency with p frequency
            if (sCount == pCount) {
                result.push_back(i - windowSize + 1);
            }
        }
        
        return result;
    }
};