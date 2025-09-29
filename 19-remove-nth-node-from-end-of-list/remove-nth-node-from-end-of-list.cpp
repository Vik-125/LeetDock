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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* dummy = new ListNode(0,head);
        ListNode* engine = dummy;
        ListNode* coaches = dummy;

        for(int i = 0; i <= n; i++) {
            engine = engine->next;
        }
        while(engine != NULL)
        {
            coaches = coaches -> next;
            engine = engine -> next;
        }
        coaches -> next = coaches -> next -> next;
        return dummy -> next;;
    }
};