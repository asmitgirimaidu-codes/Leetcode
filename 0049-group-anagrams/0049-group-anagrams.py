from collections import defaultdict

class Solution(object):
    def groupAnagrams(self, strs):
        """:type strs: List[str]
        :rtype: List[List[str]]
        """
        ans = defaultdict(list)

        for s in strs:
            # Sort the string to use as a key
            sorted_s = "".join(sorted(s))
            ans[sorted_s].append(s)

        return list(ans.values())