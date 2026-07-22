# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def preorderTraversal(self, root):
        """:type root: Optional[TreeNode]
        :rtype: List[int]
        """
        res = []
        stack = [root]
        
        while stack:
            curr = stack.pop()
            if curr:
                res.append(curr.val)
                # Push right first so that left is processed first (LIFO)
                stack.append(curr.right)
                stack.append(curr.left)
                
        return res