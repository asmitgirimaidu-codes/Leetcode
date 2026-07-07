class Solution(object):
    def sumAndMultiply(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Convert number to string to iterate over digits
        s = str(n)
        
        # Extract non-zero digits
        non_zero_chars = [char for char in s if char != '0']
        
        # If no non-zero digits exist, return 0
        if not non_zero_chars:
            return 0
        
        # Form the new integer x by joining the digits
        x = int("".join(non_zero_chars))
        
        # Calculate the sum of digits in x
        # We can iterate through the characters of the string version of x
        digit_sum = sum(int(digit) for digit in str(x))
        
        # Return the product
        return x * digit_sum