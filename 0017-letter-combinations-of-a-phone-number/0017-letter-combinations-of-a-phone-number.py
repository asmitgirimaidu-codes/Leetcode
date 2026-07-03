class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits:
            return []
        
        # Mapping of digits to letters
        phone_map = {
            "2": "abc", "3": "def", "4": "ghi", "5": "jkl",
            "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"
        }
        
        results = []
        
        def backtrack(index, path):
            # If path is complete, add to results
            if len(path) == len(digits):
                results.append(path)
                return
            
            # Get letters for the current digit
            possible_letters = phone_map[digits[index]]
            
            # Explore all letters for this digit
            for letter in possible_letters:
                backtrack(index + 1, path + letter)
        
        backtrack(0, "")
        return results