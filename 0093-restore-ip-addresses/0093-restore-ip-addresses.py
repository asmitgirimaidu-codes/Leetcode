class Solution(object):
    def restoreIpAddresses(self, s):
        """:type s: str
        :rtype: List[str]
        """
        res = []
        
        def backtrack(start, path):
            if len(path) == 4:
                if start == len(s):
                    res.append(".".join(path))
                return
            
            for i in range(start, min(start + 3, len(s))):
                segment = s[start:i + 1]
                # Check for leading zeros and range 0-255
                if (segment[0] == '0' and len(segment) > 1) or int(segment) > 255:
                    continue
                backtrack(i + 1, path + [segment])
                
        backtrack(0, [])
        return res