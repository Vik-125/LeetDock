/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> hash;

        ListNode* head1 = headA;
        while(head1)
        {
            hash[head1]++;
            head1 = head1 -> next;
        }

        ListNode* head2 = headB;
        while(head2)
        {
            if(hash.count(head2)) return head2;
            head2 = head2 -> next;
        }
        return NULL;
    }
};