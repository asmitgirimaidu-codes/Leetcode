/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        
        Node* curr = head;
        while (curr != nullptr) {
            // If there is a child, we need to insert the child list between curr and curr->next
            if (curr->child != nullptr) {
                Node* nextNode = curr->next;
                Node* childNode = curr->child;
                
                // Connect curr with child
                curr->next = childNode;
                childNode->prev = curr;
                curr->child = nullptr; // Don't forget to set child to null
                
                // Find the tail of the child list
                Node* tail = childNode;
                while (tail->next != nullptr) {
                    tail = tail->next;
                }
                
                // Attach the saved nextNode to the tail of the child list
                if (nextNode != nullptr) {
                    tail->next = nextNode;
                    nextNode->prev = tail;
                }
            }
            curr = curr->next;
        }
        
        return head;
    }
};