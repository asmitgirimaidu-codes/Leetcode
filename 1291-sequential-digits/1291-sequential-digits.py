class Solution(object):
    def sequentialDigits(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: List[int]
        """
        result = []
        # All possible starting digits
        digits = "123456789"
        
        # Length of sequential digits can range from 2 to 9
        for length in range(2, 10):
            for i in range(10 - length):
                num = int(digits[i : i + length])
                if low <= num <= high:
                    result.append(num)
                    
        return result