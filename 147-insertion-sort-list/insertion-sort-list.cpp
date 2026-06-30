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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> arr;

        while(head){
            arr.push_back(head -> val);
            head = head -> next;
        }
        sort(arr.begin(),arr.end());

        ListNode* dummy = new ListNode(0);
        ListNode* head2 = dummy;

        for(auto it : arr){
            ListNode* temp = new ListNode(it);
            dummy -> next = temp;
            dummy = dummy -> next;
        }
        return head2 -> next;
    }
};