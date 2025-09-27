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
    int check(int a, int b)
    {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head -> next) return head;
        ListNode* temp = head;

        while(temp && temp -> next)
        {
            ListNode* prev = temp;
            temp = temp -> next;
            int hcf = check(temp -> val,prev -> val);
            ListNode* mid = new ListNode(hcf,temp);
            prev -> next = mid;
        }
        return head;
    }
};