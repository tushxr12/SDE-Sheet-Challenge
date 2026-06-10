/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        for(int i = 0;i < n;i++)
            fast = fast->next;
        
        ListNode* slow = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        if(fast == NULL)
        {
            return head->next;
        }

        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete(delNode);
        return head;
    }
};
