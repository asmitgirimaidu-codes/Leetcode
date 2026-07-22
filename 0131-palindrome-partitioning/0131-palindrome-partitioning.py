class Solution(object):
    def partition(self, s):
        """:type s: str
        :rtype: List[List[str]]
        """
        res = []
        
        def is_palindrome(sub):
            return sub == sub[::-1]
            
        def backtrack(start, path):
            if start == len(s):
                res.append(list(path))
                return
                
            for i in range(start, len(s)):
                sub = s[start:i + 1]
                if is_palindrome(sub):
                    path.append(sub)
                    backtrack(i + 1, path)
                    path.pop()
                    
        backtrack(0, [])
        return res
        