#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string getHint(std::string secret, std::string guess) {
        int bulls = 0;
        int cows = 0;
        
        // Frequency arrays to track unmatched digits for secret and guess
        std::vector<int> secretCount(10, 0);
        std::vector<int> guessCount(10, 0);
        
        for (int i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                secretCount[secret[i] - '0']++;
                guessCount[guess[i] - '0']++;
            }
        }
        
        // Count cows by taking the minimum available frequency of each digit
        for (int i = 0; i < 10; ++i) {
            cows += std::min(secretCount[i], guessCount[i]);
        }
        
        return std::to_string(bulls) + "A" + std::to_string(cows) + "B";
    }
};