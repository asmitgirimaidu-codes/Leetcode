class Solution(object):
    def findTheString(self, lcp):
        """
        :type lcp: List[List[int]]
        :rtype: str
        """
        n = len(lcp)
        word = [None] * n
        curr_char = ord('a')
        
        for i in range(n):
            if word[i] is None:
                if curr_char > ord('z'):
                    return ""
                word[i] = chr(curr_char)
                curr_char += 1
            
            for j in range(i + 1, n):
                if lcp[i][j] > 0:
                    word[j] = word[i]
                    
        # Verify the LCP matrix
        # Build the LCP table from the generated word
        res = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if word[i] == word[j]:
                    res[i][j] = 1 + res[i + 1][j + 1]
                else:
                    res[i][j] = 0
                    
        for i in range(n):
            for j in range(n):
                if res[i][j] != lcp[i][j]:
                    return ""
                    
        return "".join(word)