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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());
        int result = 0;

        while (head) {
            if (hash.count(head->val) && 
               (!head->next || !hash.count(head->next->val))) {
                result++;
            }
            head = head->next;
        }

        return result;
    }
};
