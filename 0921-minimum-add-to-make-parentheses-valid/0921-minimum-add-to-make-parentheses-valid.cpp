class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_brackets = 0;
        int min_adds = 0;
        
        for (char c : s) {
            if (c == '(') {
                open_brackets++;
            } else {
                if (open_brackets > 0) {
                    open_brackets--;
                } else {
                    min_adds++;
                }
            }
        }
        
        return min_adds + open_brackets;
    }
};