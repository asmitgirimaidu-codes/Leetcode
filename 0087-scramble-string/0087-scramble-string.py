from collections import Counter

class Solution(object):
    def __init__(self):
        self.memo = {}

    def isScramble(self, s1, s2):
        """:type s1: str
        :type s2: str
        :rtype: bool
        """
        if s1 == s2:
            return True
            
        if Counter(s1) != Counter(s2):
            return False
            
        key = (s1, s2)
        if key in self.memo:
            return self.memo[key]
            
        n = len(s1)
        for i in range(1, n):
            # Case 1: No Swap
            if (self.isScramble(s1[:i], s2[:i]) and self.isScramble(s1[i:], s2[i:])) or \
               (self.isScramble(s1[:i], s2[n-i:]) and self.isScramble(s1[i:], s2[:n-i])):
                self.memo[key] = True
                return True
                
        self.memo[key] = False
        return False