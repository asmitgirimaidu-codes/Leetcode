class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        # Mapping of closing to opening brackets for easy lookup
        mapping = {")": "(", "}": "{", "]": "["}
        
        for char in s:
            # If the character is a closing bracket
            if char in mapping:
                # Pop the top element from stack if it's not empty, 
                # otherwise assign a dummy value
                top_element = stack.pop() if stack else '#'
                
                # If the popped bracket doesn't match the corresponding opening bracket
                if mapping[char] != top_element:
                    return False
            else:
                # It's an opening bracket, push onto stack
                stack.append(char)
        
        # If the stack is empty, return True; otherwise, False
        return not stack