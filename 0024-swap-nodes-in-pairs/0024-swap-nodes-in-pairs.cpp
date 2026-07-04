class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Base case: If the list is empty or has only one node, no swap is needed
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Identify the first two nodes to swap
        ListNode* firstNode = head;
        ListNode* secondNode = head->next;
        
        // Swapping logic:
        // 1. The first node's next pointer should point to the result of swapping the rest of the list
        firstNode->next = swapPairs(secondNode->next);
        
        // 2. The second node's next pointer points back to the first node
        secondNode->next = firstNode;
        
        // The second node is now the new head of this swapped pair
        return secondNode;
    }
};