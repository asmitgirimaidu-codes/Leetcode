class Solution {
private:
    bool helper(string& s, int& i) {
        char curr = s[i];
        if (curr == 't') {
            i++;
            return true;
        }
        if (curr == 'f') {
            i++;
            return false;
        }
        
        // It's an operator: '!', '&', or '|'
        char op = curr;
        i += 2; // skip operator and '('
        
        if (op == '!') {
            bool val = helper(s, i);
            i++; // skip ')'
            return !val;
        } else if (op == '&') {
            bool result = true;
            while (s[i] != ')') {
                if (s[i] == ',') {
                    i++;
                }
                bool val = helper(s, i);
                result = result && val;
            }
            i++; // skip ')'
            return result;
        } else { // op == '|'
            bool result = false;
            while (s[i] != ')') {
                if (s[i] == ',') {
                    i++;
                }
                bool val = helper(s, i);
                result = result || val;
            }
            i++; // skip ')'
            return result;
        }
    }

public:
    bool parseBoolExpr(string expression) {
        int i = 0;
        return helper(expression, i);
    }
};