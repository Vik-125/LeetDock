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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head -> next)  return head;
        ListNode* dummy = new ListNode(-1,head);
        ListNode* prev = dummy -> next; 

        while(prev && prev -> next)
        {
            ListNode* temp = prev -> next;

            if(prev -> val == temp -> val)
            {
                prev -> next = prev -> next -> next;
            }
            else prev = prev -> next;
        }
        return dummy -> next;
    }
};