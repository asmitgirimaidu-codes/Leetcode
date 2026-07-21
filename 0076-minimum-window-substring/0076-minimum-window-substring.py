class Solution(object):
    def minWindow(self, s, t):
        """:type s: str
        :type t: str
        :rtype: str
        """
        if not t or not s:
            return ""

        from collections import Counter
        dict_t = Counter(t)
        required = len(dict_t)

        left = 0
        right = 0
        formed = 0
        window_counts = {}

        # Tuple format: (window_length, left, right)
        ans = float("inf"), None, None

        while right < len(s):
            character = s[right]
            window_counts[character] = window_counts.get(character, 0) + 1

            if character in dict_t and window_counts[character] == dict_t[character]:
                formed += 1

            while left <= right and formed == required:
                character = s[left]

                if right - left + 1 < ans[0]:
                    ans = (right - left + 1, left, right)

                window_counts[character] -= 1
                if character in dict_t and window_counts[character] < dict_t[character]:
                    formed -= 1

                left += 1

            right += 1

        return "" if ans[0] == float("inf") else s[ans[1] : ans[2] + 1]