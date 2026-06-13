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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
            return head;
        
        for(int i = 0;i < k;i++)
        {
            ListNode* temp = head;
            while(temp->next->next)
                temp = temp->next;
            
            ListNode* end = temp->next;
            temp->next = NULL;
            end->next = head;
            head = end;
        }
        return head;
    }
};
