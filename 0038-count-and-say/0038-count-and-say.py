class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n == 1:
            return "1"
        
        res = "1"
        for _ in range(n - 1):
            res = self.getNext(res)
        return res
    
    def getNext(self, s):
        result = []
        i = 0
        while i < len(s):
            count = 1
            # Count consecutive identical characters
            while i + 1 < len(s) and s[i] == s[i + 1]:
                i += 1
                count += 1
            # Append the count and the character itself
            result.append(str(count))
            result.append(s[i])
            i += 1
        return "".join(result)