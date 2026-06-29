# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def sumEvenGrandparent(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.total_sum = 0
        
        def dfs(node, parent, grandparent):
            if not node:
                return
            
            # If the grandparent exists and is even, add current node's value
            if grandparent is not None and grandparent % 2 == 0:
                self.total_sum += node.val
            
            # Recurse: current node becomes parent, parent becomes grandparent
            dfs(node.left, node.val, parent)
            dfs(node.right, node.val, parent)
            
        dfs(root, None, None)
        return self.total_sum