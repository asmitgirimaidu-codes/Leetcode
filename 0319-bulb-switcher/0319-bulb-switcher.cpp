class Solution {
public:
    int bulbSwitch(int n) {
        // The number of bulbs that remain on is the number of perfect squares <= n
        return std::sqrt(n);
    }
};