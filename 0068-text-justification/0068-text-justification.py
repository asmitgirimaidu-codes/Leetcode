class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        res, cur_line, num_of_letters = [], [], 0
        
        for word in words:
            # Check if adding the new word exceeds maxWidth
            # (num_of_letters + len(cur_line)) accounts for at least one space between words
            if num_of_letters + len(word) + len(cur_line) > maxWidth:
                # Distribute spaces
                for i in range(maxWidth - num_of_letters):
                    # Cycle through words in the line (except the last word)
                    # or handle a single-word line
                    cur_line[i % (len(cur_line) - 1 or 1)] += ' '
                res.append("".join(cur_line))
                cur_line, num_of_letters = [], 0
            
            cur_line.append(word)
            num_of_letters += len(word)
            
        # Handle the last line (left-justified)
        last_line = " ".join(cur_line)
        res.append(last_line + ' ' * (maxWidth - len(last_line)))
        
        return res
        