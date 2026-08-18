class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(128, 0);
        for (char c : s) {
            count[c]++;
        }

        int length = 0;
        bool hasOdd = false;

        for (int c : count) {
            length += (c / 2) * 2;
            if (c % 2 == 1) {
                hasOdd = true;
            }
        }

        if (hasOdd) {
            length += 1;
        }

        return length;
    }
};