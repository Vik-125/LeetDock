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
        map<int,int> hash;
        for(auto it : nums) hash[it]++;

        int result = nums.size();
        bool flag = false;
        while(head && head -> next){
            if(hash.find(head -> val) != hash.end()) flag = true;
            if(flag == true && hash.find(head -> next -> val) != hash.end()){
                result--;
                head = head -> next;
            }
            else{
                head = head -> next;
                flag = false;
            }
        }
        return result;
    }
};