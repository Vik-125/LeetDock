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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        int n = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp -> next;
            n++;
        }
        while(fast -> next && fast -> next -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        if(n == 1) return NULL;
        if(n % 2 == 0) slow = slow -> next;

        temp = head;

        while(temp){
            if(temp -> next == slow){
                temp -> next = temp -> next -> next;
            }
            temp = temp -> next;
        }
        return head;
    }
};