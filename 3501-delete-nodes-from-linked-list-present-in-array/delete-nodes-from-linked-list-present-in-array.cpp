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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> hash;
        for(int it : nums)
        {
            hash[it]++;
        }

        ListNode* prev = new ListNode(-1);
        ListNode* newhead = prev;
        ListNode* temp = head;

        while(temp)
        {
            if(!hash.count(temp -> val))
            {
                prev -> next = temp;
                prev = prev -> next;
            }
            temp = temp -> next;
        }
        prev -> next = NULL;
        return newhead -> next;
    }
};