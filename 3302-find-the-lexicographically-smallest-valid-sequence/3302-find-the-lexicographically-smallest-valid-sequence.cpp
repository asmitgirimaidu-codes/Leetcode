#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> validSequence(std::string word1, std::string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        
        // suf[i] stores the minimum index in word2 such that word2[suf[i]:] 
        // can be formed as a subsequence of word1[i:]
        std::vector<int> suf(n1 + 1, n2);
        
        int j = n2 - 1;
        for (int i = n1 - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }
            suf[i] = j + 1; // First index of word2 suffix matched from word1[i:]
        }
        
        std::vector<int> result;
        j = 0; // points to current character in word2 to match
        bool changed = false;
        
        for (int i = 0; i < n1; ++i) {
            if (j == n2) break;
            
            if (word1[i] == word2[j]) {
                result.push_back(i);
                j++;
            } else if (!changed && suf[i + 1] <= j + 1) {
                // We can use our single modification here safely
                result.push_back(i);
                changed = true;
                j++;
            }
        }
        
        if (result.size() == n2) {
            return result;
        }
        
        return {};
    }
};