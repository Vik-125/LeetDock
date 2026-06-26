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

        ListNode* temp = head -> next;
        ListNode* newList = head;
        int sum = 0;

        while(temp){
            if(temp -> val == 0){
                ListNode* newNode = new ListNode(sum);
                newList -> next = newNode;
                newNode -> next = NULL;
                newList = newNode;
                sum = 0;
            }
            else {
                sum += temp -> val;
            }
            temp = temp -> next;
        }
        return head -> next;
    }
};