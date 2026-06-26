class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        result = []
        carry = 0
        
        # Pointers for both strings
        i, j = len(a) - 1, len(b) - 1
        
        while i >= 0 or j >= 0 or carry:
            total = carry
            
            if i >= 0:
                total += int(a[i])
                i -= 1
            if j >= 0:
                total += int(b[j])
                j -= 1
            
            # The bit to add is the remainder of the sum divided by 2
            result.append(str(total % 2))
            
            # The new carry is the quotient of the sum divided by 2
            carry = total // 2
            
        # The result was built in reverse, so reverse it back
        return "".join(result[::-1])