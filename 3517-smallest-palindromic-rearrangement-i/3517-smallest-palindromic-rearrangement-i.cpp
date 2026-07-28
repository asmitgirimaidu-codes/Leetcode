class Solution {
public:
    string smallestPalindrome(string s) {
        // Step 1: Count frequency of each character
        int count[26] = {0};
        for (char c : s) {
            count[c - 'a']++;
        }
        
        string left_half = "";
        string middle = "";
        
        // Step 2: Build the left half and find the middle character if length is odd
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                // Append half of the occurrences to the left half
                left_half.append(count[i] / 2, (char)('a' + i));
                
                // If the character count is odd, it goes to the center
                if (count[i] % 2 != 0) {
                    middle = string(1, (char)('a' + i));
                }
            }
        }
        
        // Step 3: Create the right half by reversing the left half
        string right_half = left_half;
        reverse(right_half.begin(), right_half.end());
        
        // Step 4: Combine parts to get the final smallest palindromic rearrangement
        return left_half + middle + right_half;
    }
};