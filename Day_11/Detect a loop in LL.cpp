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
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode *temp = head;
        unordered_set<ListNode*> st;

        while(temp)
        {
            if(st.find(temp) != st.end())
            {
                return true;
            }

            st.insert(temp);
            temp = temp->next;
        }
        return false;
    }
};

// Optimal 

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
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;

        ListNode* slow = head, *fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                return true;
        }
        return false;
    }
};
