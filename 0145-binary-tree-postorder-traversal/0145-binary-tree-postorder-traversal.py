# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def postorderTraversal(self, root):
        """:type root: Optional[TreeNode]
        :rtype: List[int]
        """
        res = []
        stack = [root]
        
        while stack:
            curr = stack.pop()
            if curr:
                res.append(curr.val)
                stack.append(curr.left)
                stack.append(curr.right)
                
        return res[::-1]