/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node to handle edge cases easily (e.g., removing the head node)
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* curr = &dummy;
        
        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                // Skip the node with the target value
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp; // Optional: free memory in C++
            } else {
                // Move forward if no match
                curr = curr->next;
            }
        }
        
        return dummy.next;
    }
};