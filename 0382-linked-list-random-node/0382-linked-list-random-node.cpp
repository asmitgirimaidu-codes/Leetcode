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
    ListNode* headNode;

public:
    Solution(ListNode* head) {
        headNode = head;
    }
    
    int getRandom() {
        int res = headNode->val;
        ListNode* curr = headNode->next;
        int i = 2;
        
        while (curr != nullptr) {
            // Reservoir sampling: select current node with probability 1/i
            if (rand() % i == 0) {
                res = curr->val;
            }
            curr = curr->next;
            i++;
        }
        
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */