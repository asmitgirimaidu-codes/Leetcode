from collections import Counter

class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if not s or not words:
            return []
        
        word_len = len(words[0])
        num_words = len(words)
        total_len = word_len * num_words
        word_count = Counter(words)
        results = []
        
        # Only need to check starting positions up to s_len - total_len
        for i in range(word_len):
            left = i
            right = i
            current_count = Counter()
            
            while right + word_len <= len(s):
                # Get the word from the right side of the window
                w = s[right : right + word_len]
                right += word_len
                
                if w in word_count:
                    current_count[w] += 1
                    # If we have too many of one word, shrink from the left
                    while current_count[w] > word_count[w]:
                        left_w = s[left : left + word_len]
                        current_count[left_w] -= 1
                        left += word_len
                    
                    # If current window length matches total length, record index
                    if right - left == total_len:
                        results.append(left)
                else:
                    # Not a valid word, reset everything
                    current_count.clear()
                    left = right
                    
        return results
        