"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution(object):
    def connect(self, root):
        """:type root: Node
        :rtype: Node
        """
        if not root:
            return None
            
        leftmost = root
        
        while leftmost.left:
            head = leftmost
            while head:
                # 1. Connect left child to right child of the same parent
                head.left.next = head.right
                
                # 2. Connect right child to the left child of the next node
                if head.next:
                    head.right.next = head.next.left
                    
                head = head.next
                
            leftmost = leftmost.left
            
        return root