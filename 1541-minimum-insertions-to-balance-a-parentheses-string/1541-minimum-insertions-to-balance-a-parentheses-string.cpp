class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int openBrackets = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                openBrackets++;
            } else {
                // We encounter a closing parenthesis ')'
                // Check if the next character is also ')'
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    i++; // Skip the next ')' as it forms a pair '))'
                } else {
                    // We need to insert one ')' to complete the pair
                    insertions++;
                }
                
                // Now we have a complete pair ')' ')'
                if (openBrackets > 0) {
                    openBrackets--;
                } else {
                    // No matching '(' available, so we need to insert an opening '('
                    insertions++;
                }
            }
        }
        
        // Each remaining unmatched opening '(' requires two closing ')'
        insertions += openBrackets * 2;
        
        return insertions;
    }
};