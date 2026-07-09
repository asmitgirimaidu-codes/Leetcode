class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        if numerator == 0:
            return "0"
        
        res = []
        # Determine the sign
        if (numerator < 0) ^ (denominator < 0):
            res.append("-")
            
        n = abs(numerator)
        d = abs(denominator)
        
        # Append the integer part
        res.append(str(n // d))
        
        # Check if there is a fractional part
        rem = n % d
        if rem == 0:
            return "".join(res)
        
        res.append(".")
        
        # Dictionary to store the index of each remainder
        rem_map = {}
        
        while rem != 0:
            if rem in rem_map:
                # Repeat found: insert parentheses
                res.insert(rem_map[rem], "(")
                res.append(")")
                break
            
            # Store the current remainder and its position
            rem_map[rem] = len(res)
            
            # Perform long division step
            rem *= 10
            res.append(str(rem // d))
            rem %= d
            
        return "".join(res)