class Solution {
public:
    int maximumLengthSubstring(string s) {
        int freq[26] = {0};
        int left = 0;
        int maxLength = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            char c = s[right];
            freq[c - 'a']++;
            
            // If the current character count exceeds 2, shrink the window from the left
            while (freq[c - 'a'] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }
            
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};