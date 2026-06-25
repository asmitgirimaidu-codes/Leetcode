class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return ""
        
        start = 0
        end = 0
        
        def expandAroundCenter(left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            # Return the length of the palindrome found
            return right - left - 1
        
        for i in range(len(s)):
            # Odd length palindromes (e.g., "aba")
            len1 = expandAroundCenter(i, i)
            # Even length palindromes (e.g., "abba")
            len2 = expandAroundCenter(i, i + 1)
            
            max_len = max(len1, len2)
            
            if max_len > (end - start):
                # Update start and end indices
                start = i - (max_len - 1) // 2
                end = i + max_len // 2
                
        return s[start:end + 1]