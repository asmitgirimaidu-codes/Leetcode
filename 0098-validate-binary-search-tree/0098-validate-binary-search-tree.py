# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        def validate(node, low=float('-inf'), high=float('inf')):
            # An empty node is a valid BST
            if not node:
                return True
            
            # The current node's value must be within the valid range
            if not (low < node.val < high):
                return False
            
            # Recursively validate subtrees with updated boundaries
            # Left child must be in (low, node.val)
            # Right child must be in (node.val, high)
            return (validate(node.left, low, node.val) and 
                    validate(node.right, node.val, high))
        
        return validate(root)