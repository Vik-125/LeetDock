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
    ListNode* reverse(ListNode* temp){
        if(!temp || !temp -> next) return temp;

        ListNode* Nhead = reverse(temp -> next);

        temp -> next -> next = temp;
        temp -> next = NULL;

        return Nhead;
    }
    void reorderList(ListNode* head) {
        ListNode* firstHalf = head;

        ListNode* fast = head;
        while(fast && fast -> next){
            fast = fast -> next -> next;
            firstHalf = firstHalf -> next;
        }
        ListNode* rev = reverse(firstHalf);
        firstHalf -> next = NULL;

        firstHalf = head;

        while(rev && rev -> next){
            ListNode* n1 = firstHalf -> next;
            ListNode* n2 = rev -> next;

            firstHalf -> next = rev;
            rev -> next = n1;

            firstHalf = n1;
            rev = n2;
        }
        return;
    }
};