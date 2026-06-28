# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: Optional[ListNode]
        :type k: int
        :rtype: Optional[ListNode]
        """
        # Helper to get the length of the list
        def get_length(node):
            length = 0
            while node:
                length += 1
                node = node.next
            return length

        dummy = ListNode(0)
        dummy.next = head
        group_prev = dummy
        
        length = get_length(head)
        
        while length >= k:
            # Current group pointers
            curr = group_prev.next
            next_node = curr.next
            
            # Reverse k-1 links
            for _ in range(k - 1):
                curr.next = next_node.next
                next_node.next = group_prev.next
                group_prev.next = next_node
                next_node = curr.next
            
            # Move group_prev to the end of the reversed group
            group_prev = curr
            length -= k
            
        return dummy.next
        