class Solution(object):
    def hasAllCodes(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
        # The total number of unique binary codes of length k is 2^k
        target_count = 1 << k
        
        # Use a set to store unique substrings of length k
        seen_codes = set()
        
        # Iterate through the string s to find all substrings of length k
        for i in range(len(s) - k + 1):
            sub = s[i:i+k]
            seen_codes.add(sub)
            
            # Optimization: If we already found all required codes, return True
            if len(seen_codes) == target_count:
                return True
        
        # Return True if the set contains all 2^k codes
        return len(seen_codes) == target_count