class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        
        # Helper function to perform backtracking
        def backtrack(curr):
            # If the current permutation is complete
            if len(curr) == len(nums):
                res.append(curr[:])
                return
            
            for num in nums:
                # If num is already in the current permutation, skip it
                if num not in curr:
                    curr.append(num)
                    backtrack(curr)
                    # Backtrack: remove the last element to try next number
                    curr.pop()
                    
        backtrack([])
        return res