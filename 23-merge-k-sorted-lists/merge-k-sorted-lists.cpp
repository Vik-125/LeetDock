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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int,int> hash;

        for(auto it : lists){
            while(it){
                hash[it->val]++;
                it = it -> next;
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        for(auto it : hash){
            int n = it.second;
            while(n > 0){
                ListNode* temp = new ListNode(it.first);
                dummy -> next = temp;
                dummy = dummy -> next;
                n--;
            }
        }
        return head -> next;
    }
};