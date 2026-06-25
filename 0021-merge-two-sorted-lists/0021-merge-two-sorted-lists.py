# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def mergeTwoLists(self, list1, list2):
        # Create a dummy node to act as the head of the new list
        dummy = ListNode(0)
        current = dummy
        
        # While both lists have nodes
        while list1 and list2:
            if list1.val <= list2.val:
                current.next = list1
                list1 = list1.next
            else:
                current.next = list2
                list2 = list2.next
            current = current.next
        
        # Attach the remaining nodes of the non-empty list
        current.next = list1 if list1 is not None else list2
        
        # The actual merged list starts after the dummy node
        return dummy.next