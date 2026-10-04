class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0, cmax = 0;
        
        for (char c : s) {
            if (c == '(') {
                cmin++;
                cmax++;
            } else if (c == ')') {
                cmin = max(0, cmin - 1);
                cmax--;
            } else { // c == '*'
                cmin = max(0, cmin - 1); // treat '*' as ')'
                cmax++;                  // treat '*' as '('
            }
            
            // If cmax drops below 0, it means we have more ')' than '(' and '*' combined
            if (cmax < 0) {
                return false;
            }
        }
        
        // At the end, the minimum number of open parentheses must be 0
        return cmin == 0;
    }
};