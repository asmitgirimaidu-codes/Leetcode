#include <vector>

class Solution {
public:
    std::vector<std::vector<char>> rotateTheBox(std::vector<std::vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        
        // Step 1: Apply gravity to each row of the box
        for (int i = 0; i < m; ++i) {
            int empty_spot = n - 1;
            for (int j = n - 1; j >= 0; --j) {
                if (boxGrid[i][j] == '*') {
                    empty_spot = j - 1;
                } else if (boxGrid[i][j] == '#') {
                    boxGrid[i][j] = '.';
                    boxGrid[i][empty_spot] = '#';
                    empty_spot--;
                }
            }
        }
        
        // Step 2: Rotate the box 90 degrees clockwise
        std::vector<std::vector<char>> rotatedBox(n, std::vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rotatedBox[j][m - 1 - i] = boxGrid[i][j];
            }
        }
        
        return rotatedBox;
    }
};