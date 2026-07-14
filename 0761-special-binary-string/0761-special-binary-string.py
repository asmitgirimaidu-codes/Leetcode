class Solution(object):
    def makeLargestSpecial(self, s):
        """
        :type s: str
        :rtype: str
        """
        count = 0
        i = 0
        mountains = []
        
        # Split string into mountain substrings
        for j, char in enumerate(s):
            if char == '1':
                count += 1
            else:
                count -= 1
            
            # When count reaches 0, we found a complete mountain
            if count == 0:
                # Process the interior: "1" + result + "0"
                # We strip the outer "1" and "0" and recurse
                mountain = "1" + self.makeLargestSpecial(s[i+1:j]) + "0"
                mountains.append(mountain)
                i = j + 1
                
        # Sort mountains in descending order for the lexicographically largest result
        mountains.sort(reverse=True)
        
        return "".join(mountains)