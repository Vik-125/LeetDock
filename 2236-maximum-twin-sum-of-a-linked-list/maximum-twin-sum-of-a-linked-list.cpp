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
    ListNode* find(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast -> next)
        {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }

    ListNode* rev(ListNode* head)
    {
        if(head == NULL || head -> next == NULL)
        {
            return head;
        }
        ListNode* newHead = rev(head -> next);
        ListNode* front = head -> next;
        front -> next = head;
        head -> next = NULL;
        return newHead;
    }
    int pairSum(ListNode* head) {
        ListNode* mid = find(head);
        ListNode* nextHead = rev(mid);

        int sum = INT_MIN;
        while(head && nextHead)
        {
            sum = max(sum,head -> val + nextHead -> val);
            head = head -> next;
            nextHead = nextHead -> next;
        }
        return sum;
    }
};