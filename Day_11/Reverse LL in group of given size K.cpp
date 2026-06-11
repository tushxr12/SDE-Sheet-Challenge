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
    ListNode* findKthNode(ListNode* temp, int k)
    {
        k -= 1;
        while(temp && k)
        {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseLinkedList(ListNode* head)
    {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp)
        {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while(temp != NULL)
        {
            ListNode* kThNode = findKthNode(temp, k);

            if(!kThNode){
                if(prevLast){
                    prevLast->next = temp;
                }
                break;
            }

            ListNode* nextNode = kThNode->next;

            kThNode->next = NULL;

            reverseLinkedList(temp);

            if(temp == head)
            {
                head = kThNode;
            }
            else
            {
                prevLast->next = kThNode;
            }

            prevLast = temp;
            temp = nextNode;

        }
        return head;
    }
};
