#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string winningPlayer(int x, int y) {
        // Calculate the maximum number of full turns possible
        int turns = min(x, y / 4);
        
        // If the number of turns is odd, Alice wins; otherwise, Bob wins
        if (turns % 2 != 0) {
            return "Alice";
        } else {
            return "Bob";
        }
    }
};