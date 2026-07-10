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
        int k = min(a,b);

        while(k >= 1){
            if(a % k == 0 && b % k == 0){
                return k;
            }
            k--;
        }
        return k;
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