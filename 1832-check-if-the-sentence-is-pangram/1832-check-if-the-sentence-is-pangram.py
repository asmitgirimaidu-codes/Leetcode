class Solution(object):
    def checkIfPangram(self, sentence):
        """
        :type sentence: str
        :rtype: bool
        """
        # A set only contains unique characters
        return len(set(sentence)) == 26