class Solution {
private:
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        // If the current string reaches the length of 2 * n, we've found a valid combination
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // We can add an opening parenthesis if we haven't used all 'n' opening brackets yet
        if (open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }

        // We can add a closing parenthesis if the number of closing brackets is less than the opening brackets
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};