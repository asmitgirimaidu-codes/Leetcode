class Solution(object):
    def binaryGap(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Convert n to binary string and ignore '0b' prefix
        binary_str = bin(n)[2:]
        
        max_dist = 0
        last_index = -1
        
        # Iterate through the binary string with indices
        for i, bit in enumerate(binary_str):
            if bit == '1':
                # If we have seen a 1 before, calculate the distance
                if last_index != -1:
                    max_dist = max(max_dist, i - last_index)
                # Update the last_index to the current 1's position
                last_index = i
                
        return max_dist