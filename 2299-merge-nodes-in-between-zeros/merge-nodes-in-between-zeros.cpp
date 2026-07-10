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
    ListNode* mergeNodes(ListNode* head) {
        if(!head -> next)  return NULL;

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int sum = 0;

        while(head){
            if(head -> val == 0) {
                if(sum != 0){
                    ListNode* mid = new ListNode(sum);
                    sum = 0;
                    temp -> next = mid;
                    temp = mid;
                }
            }
            else sum += head -> val;
            head = head -> next;
        }
        return dummy -> next;
    }
};