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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;

        while(temp)
        {
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;
        while(temp)
        {
            if(temp->val != st.top())
                return false;
            st.pop();
            temp = temp->next;
        }
        return true;
    }
};
