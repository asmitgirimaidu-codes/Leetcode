class Solution(object):
    def numSteps(self, s):
        """
        :type s: str
        :rtype: int
        """
        steps = 0
        carry = 0
        # Process from right to left (excluding the last bit until the end)
        for i in range(len(s) - 1, 0, -1):
            bit = int(s[i])
            if bit + carry == 1:
                # Number is odd: add 1 (makes it even), then divide by 2
                steps += 2
                carry = 1
            else:
                # Number is even: just divide by 2
                steps += 1
        
        # If there is a final carry, we need one more step to reach 1
        return steps + carry