from collections import deque

class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """:type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        word_set = set(wordList)
        if endWord not in word_set:
            return 0
            
        queue = deque([(beginWord, 1)])
        word_set.discard(beginWord)
        
        while queue:
            curr, level = queue.popleft()
            if curr == endWord:
                return level
                
            curr_chars = list(curr)
            for i in range(len(curr_chars)):
                original_char = curr_chars[i]
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    if c == original_char:
                        continue
                    curr_chars[i] = c
                    next_word = "".join(curr_chars)
                    
                    if next_word in word_set:
                        word_set.remove(next_word)
                        queue.append((next_word, level + 1))
                        
                curr_chars[i] = original_char
                
        return 0