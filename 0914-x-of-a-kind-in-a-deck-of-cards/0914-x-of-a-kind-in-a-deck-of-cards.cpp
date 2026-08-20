#include <vector>
#include <unordered_map>
#include <numeric>

class Solution {
public:
    bool hasGroupsSizeX(std::vector<int>& deck) {
        std::unordered_map<int, int> countMap;
        for (int card : deck) {
            countMap[card]++;
        }

        int gcdVal = 0;
        for (auto& pair : countMap) {
            gcdVal = std::gcd(gcdVal, pair.second);
        }

        return gcdVal >= 2;
    }
};