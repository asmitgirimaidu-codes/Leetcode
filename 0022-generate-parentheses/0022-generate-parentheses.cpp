class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
    
private:
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        // Base case: If the current string has reached the maximum length (2 * n)
        if (current.length() == n * 2) {
            result.push_back(current);
            return;
        }
        
        // If we haven't used all the open parentheses, we can add one
        if (open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }
        
        // If we have more open parentheses than close parentheses, we can add a close parenthesis 
        // to keep it well-formed
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }
};