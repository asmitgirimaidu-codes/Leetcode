class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        
        // Step 1: Precompute the length of the string after processing each prefix of s.
        // len[i] will store the length of the result string after considering s[0...i].
        vector<unsigned long long> len(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            unsigned long long cur = len[i];
            if (s[i] >= 'a' && s[i] <= 'z') {
                cur += 1;
            } else if (s[i] == '*') {
                if (cur > 0) cur -= 1;
            } else if (s[i] == '#') {
                cur *= 2;
            } else if (s[i] == '%') {
                // '%' reverses the string, length stays the same
                cur = cur; 
            }
            // Clamp to avoid overflow if it exceeds a very large cap (since k <= 10^15)
            len[i + 1] = min(cur, (unsigned long long)2e16);
        }
        
        // If k is out of bounds of the final string, return '.'
        if (k >= len[n]) {
            return '.';
        }
        
        // Step 2: Walk backwards through the string to trace back the position k
        for (int i = n - 1; i >= 0; --i) {
            if (k >= len[i + 1]) {
                return '.';
            }
            
            char op = s[i];
            if (op >= 'a' && op <= 'z') {
                // If we reach the point where this character was appended and len[i] <= k, 
                // this must be the exact character at index k.
                if (k == len[i]) {
                    return op;
                }
            } else if (op == '#') {
                // '#' duplicated the string: result was [prev_string + prev_string]
                unsigned long long half = len[i];
                if (k >= half) {
                    k -= half;
                }
            } else if (op == '%') {
                // '%' reversed the string: result was reversed
                unsigned long long total_len = len[i];
                k = total_len - 1 - k;
            } else if (op == '*') {
                // '*' removed the last character, so length at i+1 is len[i] - 1 (if len[i] > 0)
                // Position k is unaffected since '*' only removes from the end.
                continue;
            }
        }
        
        return '.';
    }
};