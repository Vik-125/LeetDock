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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
       int cnt = 0;
       ListNode* temp = head;
       while(temp){
        cnt++;
        temp = temp -> next;
       }

       vector<ListNode*> result(k);
       int rem = cnt % k;
       int n = cnt / k;

       for(int i=0;i<k;i++){

        if(!head) break;
        result[i] = head;

        int current_part_size = n + (rem > 0 ? 1 : 0);
        rem--;
        
        for(int j=1;j<current_part_size;j++)
        {
            if(head) head = head -> next;
        }
        ListNode* temp = head -> next;
        head -> next = NULL;
        head = temp;
       }
       return result;   
    }
};