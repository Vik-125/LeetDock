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
    ListNode* reverseN(ListNode* &head){
        if(head == NULL) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode* newH = reverseN(head);
        ListNode* temp = newH;

        int maxi = temp -> val;
        while(temp -> next){
            if(temp -> next -> val >= maxi){
                maxi = temp -> next -> val;
                temp = temp -> next;
            }
            else{
                temp -> next = temp -> next -> next;
            }
        }

        return reverseN(newH);
    }
};