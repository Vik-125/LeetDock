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
        unordered_map<int,int> hash;
        ListNode* temp = head;
        if(temp == NULL) return head;
        hash[head -> val]++;

        while(temp && temp -> next){
            if(hash.find(temp -> next -> val) == hash.end()){
                hash[temp -> next -> val]++;
                temp = temp -> next;
            }
            else temp -> next = temp -> next -> next;
        }
        return head;
    }
};