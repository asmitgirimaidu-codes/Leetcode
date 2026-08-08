#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>

class Solution {
private:
    std::unordered_map<std::string, int> memo;

    // Helper to clean up the board by removing groups of 3 or more consecutive identical balls
    std::string cleanBoard(std::string board) {
        bool changed = true;
        while (changed) {
            changed = false;
            for (int i = 0, j = 0; i < board.length(); i = j) {
                while (j < board.length() && board[j] == board[i]) {
                    j++;
                }
                if (j - i >= 3) {
                    board.erase(i, j - i);
                    changed = true;
                    break;
                }
            }
        }
        return board;
    }

    int dfs(std::string board, std::string hand) {
        board = cleanBoard(board);
        if (board.empty()) return 0;
        if (hand.empty()) return -1;

        std::string key = board + "_" + hand;
        if (memo.count(key)) return memo[key];

        int minBalls = INT_MAX;

        for (int i = 0; i < board.length(); ++i) {
            for (int j = 0; j < hand.length(); ++j) {
                // Optimization: Skip duplicate balls in hand to avoid redundant states
                if (j > 0 && hand[j] == hand[j - 1]) continue;

                // Optimization: Only insert if it matches the current board ball, 
                // or if it fills a gap between two balls of the same color
                bool shouldInsert = false;
                if (board[i] == hand[j]) {
                    shouldInsert = true;
                } else if (i > 0 && board[i - 1] == board[i] && board[i] != hand[j]) {
                    // If inserting next to a pair of the same color
                    shouldInsert = true;
                }

                if (shouldInsert) {
                    std::string nextBoard = board;
                    nextBoard.insert(nextBoard.begin() + i, hand[j]);
                    
                    std::string nextHand = hand;
                    nextHand.erase(j, 1);

                    int res = dfs(nextBoard, nextHand);
                    if (res != -1) {
                        minBalls = std::min(minBalls, res + 1);
                    }
                }
            }
        }

        return memo[key] = (minBalls == INT_MAX ? -1 : minBalls);
    }

public:
    int findMinStep(std::string board, std::string hand) {
        memo.clear();
        // Sort hand to easily skip duplicate colored balls in DFS
        std::sort(hand.begin(), hand.end());
        return dfs(board, hand);
    }
};