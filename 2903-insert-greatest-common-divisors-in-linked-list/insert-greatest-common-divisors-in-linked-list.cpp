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
    int findHCF(int a, int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head -> next) return head;

        ListNode* temp = head;
        while(temp && temp -> next){
            ListNode* next = temp -> next;
            int a = temp -> val;
            int b = temp -> next -> val;

            int hcf = findHCF(a, b);

            ListNode* mid = new ListNode(hcf);
            temp -> next = mid;
            mid -> next = next;
            temp = next;
        }
        return head;
    }
};