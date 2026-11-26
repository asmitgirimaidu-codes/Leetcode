class Solution {
public:
    bool canAliceWin(int n) {
        int removeCount = 10;
        bool aliceTurn = true;

        while (n >= removeCount) {
            n -= removeCount;
            removeCount--;
            aliceTurn = !aliceTurn;
        }

        // The player whose turn it is now cannot make a move,
        // so the *previous* player wins.
        return !aliceTurn;
    }
};