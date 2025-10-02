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
        if(!head || !head -> next) return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* blow = dummy;

        head = head -> next;
        int sum = 0;
        while (head) {
            if (head->val != 0) {
                sum += head->val;
            } else {
                blow -> next = new ListNode(sum);
                blow = blow -> next;
                sum = 0;
            }
            head = head->next;
        }
        return dummy -> next;
    }
};