class Solution(object):
    def countBinarySubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Step 1: Count consecutive groups
        groups = []
        count = 1
        for i in range(1, len(s)):
            if s[i] == s[i-1]:
                count += 1
            else:
                groups.append(count)
                count = 1
        groups.append(count)
        
        # Step 2: Sum the minimums of adjacent groups
        total = 0
        for i in range(1, len(groups)):
            total += min(groups[i-1], groups[i])
            
        return total