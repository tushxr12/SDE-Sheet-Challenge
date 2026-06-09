// Definition of singly linked list:
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int data1)
//     {
//         val = data1;
//         next = NULL;
//     }
//     ListNode(int data1, ListNode *next1)
//     {
//         val = data1;
//         next = next1;
//     }
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1, *t2 = list2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(t1 && t2)
        {
            if(t1->val < t2->val)
            {
                temp->next = t1;
                t1 = t1->next;
            }
            else
            {
                temp->next = t2;
                t2 = t2->next;
            }
            temp = temp->next;
        }

        if(t1)
        {
            temp->next = t1;
        }
        if(t2)
        {
            temp->next = t2;
        }
        return dummyNode->next;
    }
};
