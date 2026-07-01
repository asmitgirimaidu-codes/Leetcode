class Solution(object):
    def maxNumberOfBalloons(self, text):
        """
        :type text: str
        :rtype: int
        """
        # Count the frequency of each character
        counts = {}
        for char in text:
            counts[char] = counts.get(char, 0) + 1
            
        # The word "balloon" requires:
        # b:1, a:1, l:2, o:2, n:1
        return min(
            counts.get('b', 0),
            counts.get('a', 0),
            counts.get('l', 0) // 2,
            counts.get('o', 0) // 2,
            counts.get('n', 0)
        )