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
public:
    ListNode* find(ListNode* head,int k)
    {
        ListNode* tail = head;
        k -= 1;
        while(tail && k > 0) 
        {
            tail = tail -> next;
            k--;
        }
        return tail;
    }
    ListNode* reverse(ListNode* head)
    {   if(head == NULL || head -> next == NULL)
            {
                return head;
            }
            ListNode* newHead = reverse(head -> next);
            ListNode* front = head -> next;
            front -> next = head;
            head -> next = NULL;
            return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while(temp)
        {
            ListNode* kth = find(temp,k);
            if(kth == NULL)
            {
                if(prevNode) prevNode -> next = temp;
                break;
            }
            ListNode* nextNode = kth -> next;
            kth -> next = NULL;

            reverse(temp);

            if(temp == head) head = kth;
            else prevNode -> next = kth;

            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};