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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> hash;
        ListNode* temp = head;
    
        while(temp){
            hash[temp -> val]++;
            temp = temp -> next;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* heed = dummy;

        for(auto it : hash){
            cout << it.first;
            if(it.second == 1){
                ListNode* curr = new ListNode(it.first);
                dummy -> next = curr;
                dummy = dummy -> next;
            }
        }
        return heed -> next;
    }
};