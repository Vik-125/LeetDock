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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* dummy = new ListNode(NULL, head);
        ListNode* curr = head;
        ListNode* prev = dummy;
        int groupSize = 1;

        while (curr) {
            int cnt = 0;
            ListNode* temp = curr;
            while (temp && groupSize > cnt) {
                temp = temp->next;
                cnt++;
            }

            if (cnt % 2 != 0) {
                while (cnt > 0) {
                    prev = curr;
                    curr = curr->next;

                    cnt--;
                } 
            } else {
                ListNode* groupPrev = prev;
                ListNode* groupEnd = curr;
                ListNode* nextGroupHead = temp;

                ListNode* p = curr;
                ListNode* q = NULL;
                while (cnt > 0) {
                    ListNode* nexty = p->next;

                    p->next = q;

                    q = p;
                    p = nexty;
                    cnt--;
                }
                groupPrev->next = q;
                groupEnd->next = nextGroupHead;
                prev = groupEnd;
                curr = nextGroupHead;
            }
            groupSize++;
        }
        return dummy->next;
    }
};