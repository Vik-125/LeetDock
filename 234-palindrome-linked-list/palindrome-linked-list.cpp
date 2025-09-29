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
    ListNode* reverse(ListNode* head)
    {
        if(!head || !head -> next) return head;
        ListNode* newHead = reverse(head -> next);
        ListNode* front = head -> next;
        front -> next = head;
        head -> next = NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head -> next) return true;
        ListNode* slow = head;
        ListNode* fast = head -> next -> next;

        while(fast && fast -> next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* newhead = reverse(slow -> next);

        ListNode* newslow = head;
        while(newhead)
        {
            if(newslow -> val != newhead -> val) 
            {
                reverse(slow -> next);
                return false;
            }
            newslow = newslow -> next;
            newhead = newhead -> next;
        }
        reverse(slow -> next);
        return true;
    }
};