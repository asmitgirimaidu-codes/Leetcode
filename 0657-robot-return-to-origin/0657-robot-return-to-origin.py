class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        # The robot returns to origin if moves cancel each other out
        return moves.count('U') == moves.count('D') and moves.count('L') == moves.count('R')