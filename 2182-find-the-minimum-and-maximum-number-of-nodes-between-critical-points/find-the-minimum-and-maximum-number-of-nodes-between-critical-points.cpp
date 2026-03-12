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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = temp;
        temp = temp -> next;

        int cp = 0;
        int firstCP = -1;
        int prevCP = firstCP;
        int mini = INT_MAX;
        while(temp -> next)
        {
            int pa = prev -> val;
            int pre = temp -> val;
            int fu = temp -> next -> val;
            if(pa < pre && pre > fu || pa > pre && fu > pre) 
            {
                if (firstCP == -1) {
                    firstCP = cp;
                } else {
                    mini = min(mini, cp - prevCP);
                }
                prevCP = cp;
            }
            prev = temp;
            temp = temp -> next;
            cp++;
        }
        if (firstCP == prevCP) return {-1, -1};
        return {mini, prevCP - firstCP};
    }
};