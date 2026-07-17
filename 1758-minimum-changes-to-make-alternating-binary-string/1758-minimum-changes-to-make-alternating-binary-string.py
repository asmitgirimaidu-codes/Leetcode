class Solution(object):
    def minOperations(self, s):
        """
        :type s: str
        :rtype: int
        """
        ops_starting_with_0 = 0
        
        # Count operations needed to make s match "0101..."
        # An alternating string "0101..." has '0' at even indices
        # and '1' at odd indices.
        for i in range(len(s)):
            if i % 2 == 0:
                if s[i] != '0':
                    ops_starting_with_0 += 1
            else:
                if s[i] != '1':
                    ops_starting_with_0 += 1
                    
        # The pattern starting with '1' is the exact inverse,
        # so operations = len(s) - ops_starting_with_0
        return min(ops_starting_with_0, len(s) - ops_starting_with_0)