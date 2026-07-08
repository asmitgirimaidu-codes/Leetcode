# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: Optional[TreeNode]
        """
        # Map inorder values to their indices for O(1) lookup
        inorder_map = {val: i for i, val in enumerate(inorder)}
        
        def helper(in_left, in_right):
            # Base case: no elements to construct the tree
            if in_left > in_right:
                return None
            
            # The last element in postorder is the root
            root_val = postorder.pop()
            root = TreeNode(root_val)
            
            # Get the index of the root in inorder traversal
            index = inorder_map[root_val]
            
            # Recursively build the right subtree first
            # (Because we are popping from the end of postorder)
            root.right = helper(index + 1, in_right)
            root.left = helper(in_left, index - 1)
            
            return root
        
        return helper(0, len(inorder) - 1)