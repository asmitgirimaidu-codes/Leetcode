class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        jumps = 0
        current_end = 0
        farthest = 0
        
        # We don't need to jump from the last index, so iterate to n-1
        for i in range(len(nums) - 1):
            # Update the farthest point reachable from current or previous positions
            farthest = max(farthest, i + nums[i])
            
            # If we have reached the end of the range for the current jump
            if i == current_end:
                jumps += 1
                current_end = farthest
                
                # Optimization: if we can already reach the end, break early
                if current_end >= len(nums) - 1:
                    break
                    
        return jumps