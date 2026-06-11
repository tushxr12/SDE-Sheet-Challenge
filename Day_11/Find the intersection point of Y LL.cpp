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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return NULL;
        
        ListNode* d1 = headA, *d2 = headB;

        while(d1 != d2)
        {
            d1 = (d1 == NULL) ? headB : d1->next;
            d2 = (d2 == NULL) ? headA : d2->next;
        }
        return d1;
    }
};
