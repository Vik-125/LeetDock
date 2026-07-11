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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        int cnt = 0;
        while(first){
            cnt++;
            first = first -> next;
        }

        int r = cnt - k + 1;

        first = head;
        for(int i=1;i<k;i++){
            first = first -> next;
        }

        ListNode* second = head;
        for(int i=1;i<r;i++){
            second = second -> next;
        }
        int temp = first -> val;
        first -> val = second -> val;
        second -> val = temp;
        return head;
    }
};