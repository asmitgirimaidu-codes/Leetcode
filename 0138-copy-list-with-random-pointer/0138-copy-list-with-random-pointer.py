"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution(object):
    def copyRandomList(self, head):
        """:type head: Node
        :rtype: Node
        """
        if not head:
            return None
            
        # Step 1: Create new nodes and weave them into the original list
        curr = head
        while curr:
            new_node = Node(curr.val, curr.next)
            curr.next = new_node
            curr = new_node.next
            
        # Step 2: Assign random pointers for the copied nodes
        curr = head
        while curr:
            if curr.random:
                curr.next.random = curr.random.next
            curr = curr.next.next
            
        # Step 3: Unweave the lists to restore the original list and extract the copy
        curr = head
        copy_head = head.next
        while curr:
            copy_node = curr.next
            curr.next = copy_node.next
            curr = curr.next
            if curr:
                copy_node.next = curr.next
                
        return copy_head