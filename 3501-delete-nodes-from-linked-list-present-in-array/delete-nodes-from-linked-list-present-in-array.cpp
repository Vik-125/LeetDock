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
        unordered_set<int> hash(nums.begin(),nums.end());

        ListNode* prev = new ListNode(-1);
        ListNode* newhead = prev;
        ListNode* temp = head;

        while(temp)
        {
            if(hash.find(temp -> val) == hash.end())
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