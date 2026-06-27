from collections import Counter
import math

class Solution(object):
    def maximumLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        counts = Counter(nums)
        ans = 1
        
        # Handle 1s separately
        if 1 in counts:
            ones = counts[1]
            if ones % 2 == 0:
                ans = max(ans, ones - 1)
            else:
                ans = max(ans, ones)
        
        # Handle x > 1
        for x in counts:
            if x == 1:
                continue
            
            curr = x
            length = 0
            while curr in counts and counts[curr] > 0:
                if counts[curr] >= 2:
                    length += 2
                    curr = curr * curr
                else:
                    length += 1
                    break
            
            # If the chain ends on a single element, the formula is 2*n - 1
            # If the loop finished exactly on a single element (not >=2),
            # the last element was already counted as +1.
            if length % 2 == 0:
                ans = max(ans, length - 1)
            else:
                ans = max(ans, length)
                
        return ans