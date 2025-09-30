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
        int cnt = 1;
        while(head)
        {
            if(cnt == k) return head;
            head = head -> next;
            cnt++;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0 || !head -> next) return head;

        ListNode* tail = head;
        int len = 1;
        while(tail -> next)
        {
            tail = tail -> next;
            len++;
        }

        if(k % len == 0) return head;
        k = k % len;

        tail -> next = head;
        ListNode* lastNewTail = find(head,len-k);

        head = lastNewTail -> next;
        lastNewTail -> next = NULL;

        return head;
    }
};