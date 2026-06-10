class Solution {
public:
    void deleteNode(ListNode* node) {
        // Your code goes here
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
