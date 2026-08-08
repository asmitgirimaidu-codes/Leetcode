#include <unordered_map>

class Solution {
private:
    std::unordered_map<int, bool> memo;

    bool helper(int maxChoosableInteger, int desiredTotal, int state) {
        if (memo.count(state)) {
            return memo[state];
        }

        for (int i = 1; i <= maxChoosableInteger; ++i) {
            int mask = (1 << (i - 1));
            if (!(state & mask)) { // If the integer 'i' has not been chosen yet
                // If choosing 'i' immediately reaches/exceeds desiredTotal, or forces the opponent to lose
                if (i >= desiredTotal || !helper(maxChoosableInteger, desiredTotal - i, state | mask)) {
                    return memo[state] = true;
                }
            }
        }

        return memo[state] = false;
    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        // Quick check: if the sum of all choosable integers is less than desiredTotal, nobody can win
        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (sum < desiredTotal) {
            return false;
        }
        // If desiredTotal is 0 or less, the first player wins immediately
        if (desiredTotal <= 0) {
            return true;
        }

        memo.clear();
        return helper(maxChoosableInteger, desiredTotal, 0);
    }
};