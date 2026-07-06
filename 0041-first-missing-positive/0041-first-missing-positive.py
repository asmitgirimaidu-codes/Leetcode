class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        
        # Cyclic sort: Place each number i at index i-1 if possible
        for i in range(n):
            # Check if nums[i] is in the valid range [1, n] 
            # and if it is not already in its correct position
            while 1 <= nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                # Swap nums[i] with the element at its target position
                target_idx = nums[i] - 1
                nums[i], nums[target_idx] = nums[target_idx], nums[i]
        
        # Scan the array to find the first index where the value is incorrect
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1
        
        # If all positions are correct, the missing number is n + 1
        return n + 1