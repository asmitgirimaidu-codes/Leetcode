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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        
        // Step 1: Find the middle of the linked list using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half of the list
        ListNode* secondHalfHead = reverseList(slow);
        ListNode* copySecondHalf = secondHalfHead; // To restore later if needed
        
        // Step 3: Check if the first half and reversed second half match
        ListNode* firstHalfPtr = head;
        ListNode* secondHalfPtr = secondHalfHead;
        bool result = true;
        
        while (secondHalfPtr != nullptr) {
            if (firstHalfPtr->val != secondHalfPtr->val) {
                result = false;
                break;
            }
            firstHalfPtr = firstHalfPtr->next;
            secondHalfPtr = secondHalfPtr->next;
        }
        
        // Step 4: (Optional) Restore the list by reversing the second half back
        reverseList(copySecondHalf);
        
        return result;
    }
};