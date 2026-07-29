class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};

        // Count frequencies of each character
        for (char c : s) {
            count[c - 'a']++;
        }

        // Find the first character with a frequency of 1
        for (int i = 0; i < s.length(); i++) {
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};