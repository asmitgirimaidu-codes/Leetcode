class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        
        # Start by assuming the first string is the common prefix
        prefix = strs[0]
        
        # Compare the prefix with every other string in the list
        for i in range(1, len(strs)):
            # While the current string does not start with the prefix
            while not strs[i].startswith(prefix):
                # Shorten the prefix from the end
                prefix = prefix[:-1]
                
                # If prefix becomes empty, there's no commonality
                if not prefix:
                    return ""
                    
        return prefix