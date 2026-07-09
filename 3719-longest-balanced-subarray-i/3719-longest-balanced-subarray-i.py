class Solution(object):
    def longestBalanced(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        max_len = 0
        
        # Iterate over every possible starting point of a subarray
        for i in range(n):
            even_nums = set()
            odd_nums = set()
            
            # Iterate over every possible ending point
            for j in range(i, n):
                if nums[j] % 2 == 0:
                    even_nums.add(nums[j])
                else:
                    odd_nums.add(nums[j])
                
                # Check if the number of distinct elements is equal
                if len(even_nums) == len(odd_nums):
                    current_len = j - i + 1
                    if current_len > max_len:
                        max_len = current_len
                        
        return max_len