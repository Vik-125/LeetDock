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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return NULL;
        if(!head -> next) return head;

        ListNode dummy(0,head);
        ListNode* temp = &dummy;
        while(temp -> next && temp -> next -> next){
            ListNode* first = temp -> next;
            ListNode* second = temp -> next -> next;

            first -> next = second -> next;
            second -> next = first;
            temp -> next = second;

            temp = first;
        }
        return dummy.next;
    }
};