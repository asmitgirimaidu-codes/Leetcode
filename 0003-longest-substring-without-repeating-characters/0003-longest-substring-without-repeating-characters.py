class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        used_chars = {}
        max_length = 0
        left = 0
        
        for right, char in enumerate(s):
            # If the character is already in the map and within the current window
            if char in used_chars and used_chars[char] >= left:
                # Move the left boundary to the right of the previous occurrence
                left = used_chars[char] + 1
            
            # Update the last seen index of the character
            used_chars[char] = right
            
            # Calculate length and update max_length
            max_length = max(max_length, right - left + 1)
            
        return max_length