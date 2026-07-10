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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head = list1;

        ListNode* linkStart = list1;
        ListNode* linkEnd = list1;

        while(b > 0){
            linkEnd = linkEnd -> next;
            b--;
        }
        while(a > 1){
            linkStart = linkStart -> next;
            a--;
        }

        linkStart -> next = list2;
        while(list2){
            linkStart = linkStart -> next;
            list2 = list2 -> next;
        }
        linkStart  -> next = linkEnd -> next;

        return head;
    }
};