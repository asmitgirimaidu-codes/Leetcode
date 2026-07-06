class Solution(object):
    def minOperations(self, nums, x):
        """
        :type nums: List[int]
        :type x: int
        :rtype: int
        """
        target = sum(nums) - x
        
        # If target is negative, x is greater than the total sum
        if target < 0:
            return -1
        # If target is 0, we must remove all elements
        if target == 0:
            return len(nums)
        
        max_len = -1
        current_sum = 0
        left = 0
        
        for right in range(len(nums)):
            current_sum += nums[right]
            
            # Shrink window if current_sum exceeds target
            while current_sum > target and left <= right:
                current_sum -= nums[left]
                left += 1
            
            # Check if we found the target sum
            if current_sum == target:
                max_len = max(max_len, right - left + 1)
        
        return len(nums) - max_len if max_len != -1 else -1