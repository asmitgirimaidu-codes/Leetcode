class Solution(object):
    def wordBreak(self, s, wordDict):
        """:type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        word_set = set(wordDict)
        memo = {}
        
        def backtrack(sub):
            if sub in memo:
                return memo[sub]
            if not sub:
                return [""]
                
            res = []
            for i in range(1, len(sub) + 1):
                prefix = sub[:i]
                if prefix in word_set:
                    for suffix_sentence in backtrack(sub[i:]):
                        if suffix_sentence:
                            res.append(prefix + " " + suffix_sentence)
                        else:
                            res.append(prefix)
                            
            memo[sub] = res
            return res
            
        return backtrack(s)