class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        if num1 == "0" or num2 == "0":
            return "0"
        
        # The result of multiplying two numbers of length m and n
        # has at most m + n digits.
        m, n = len(num1), len(num2)
        res = [0] * (m + n)
        
        # Traverse from right to left
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                mul = int(num1[i]) * int(num2[j])
                
                # Position in result array
                p1, p2 = i + j, i + j + 1
                total = mul + res[p2]
                
                # Add to result array and handle carry
                res[p2] = total % 10
                res[p1] += total // 10
                
        # Convert result array back to string
        # Skip leading zero if exists
        result_str = "".join(map(str, res))
        return result_str.lstrip("0")