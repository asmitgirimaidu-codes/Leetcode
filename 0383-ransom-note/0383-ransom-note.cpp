class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Since the strings consist of lowercase English letters, 
        // we can use a fixed-size frequency array instead of an unordered_map for better performance.
        int charCount[26] = {0};

        // Count each character in the magazine
        for (char c : magazine) {
            charCount[c - 'a']++;
        }

        // Subtract the count for each character needed in the ransomNote
        for (char c : ransomNote) {
            charCount[c - 'a']--;
            // If the count drops below zero, it means magazine doesn't have enough of this character
            if (charCount[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};