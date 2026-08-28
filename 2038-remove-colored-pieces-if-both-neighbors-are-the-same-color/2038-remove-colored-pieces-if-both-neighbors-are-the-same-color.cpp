#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int aliceMoves = 0;
        int bobMoves = 0;
        int n = colors.length();
        
        // Count consecutive matching characters
        for (int i = 1; i < n - 1; ++i) {
            if (colors[i] == 'A' && colors[i - 1] == 'A' && colors[i + 1] == 'A') {
                aliceMoves++;
            } else if (colors[i] == 'B' && colors[i - 1] == 'B' && colors[i + 1] == 'B') {
                bobMoves++;
            }
        }
        
        // Alice wins if she has strictly more moves than Bob
        return aliceMoves > bobMoves;
    }
};