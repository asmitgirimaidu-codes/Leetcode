class Solution {
public:
    bool divisorGame(int n) {
        // Alice wins if and only if n is even
        return n % 2 == 0;
    }
};