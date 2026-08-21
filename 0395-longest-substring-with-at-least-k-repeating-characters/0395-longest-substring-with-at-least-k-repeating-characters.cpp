class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if (n == 0 || n < k) return 0;
        if (k <= 1) return n;

        // Count frequencies of each character
        unordered_map<char, int> counts;
        for (char c : s) {
            counts[c]++;
        }

        // Find the first character that violates the condition (frequency < k)
        int idx = 0;
        while (idx < n && counts[s[idx]] >= k) {
            idx++;
        }

        // If no character violated the condition, the whole string is valid
        if (idx == n) return n;

        // Otherwise, split the string at this character and conquer
        int left = longestSubstring(s.substr(0, idx), k);
        
        // Skip all consecutive instances of the invalid character
        int nextStart = idx;
        while (nextStart < n && counts[s[nextStart]] < k) {
            nextStart++;
        }
        
        int right = longestSubstring(s.substr(nextStart), k);

        return max(left, right);
    }
};