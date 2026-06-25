class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        n = len(digits)
        
        # Traverse backwards
        for i in range(n - 1, -1, -1):
            if digits[i] < 9:
                digits[i] += 1
                return digits
            
            # If the digit is 9, it becomes 0
            digits[i] = 0
            
        # If we exit the loop, all digits were 9
        # Insert 1 at the beginning
        return [1] + digits
        