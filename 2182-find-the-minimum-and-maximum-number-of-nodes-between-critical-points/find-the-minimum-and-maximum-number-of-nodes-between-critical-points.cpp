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
        // ListNode* temp = head;
        // ListNode* prev = temp;
        // temp = temp -> next;

        // int cp = 0;
        // int firstCP = -1;
        // int prevCP = firstCP;
        // int mini = INT_MAX;
        // while(temp -> next)
        // {
        //     int pa = prev -> val;
        //     int pre = temp -> val;
        //     int fu = temp -> next -> val;
        //     if(pa < pre && pre > fu || pa > pre && fu > pre) 
        //     {
        //         if (firstCP == -1) {
        //             firstCP = cp;
        //         } else {
        //             mini = min(mini, cp - prevCP);
        //         }
        //         prevCP = cp;
        //     }
        //     prev = temp;
        //     temp = temp -> next;
        //     cp++;
        // }
        // if (firstCP == prevCP) return {-1, -1};
        // return {mini, prevCP - firstCP};


        vector<int> cp;
        ListNode* temp = head -> next;
        ListNode* prev = head;
        int i = 2;

        while(temp && temp -> next){
            if(prev -> val < temp -> val && temp -> val > temp -> next ->  val) cp.push_back(i);
            else if(prev -> val > temp -> val && temp -> val < temp -> next ->  val) cp.push_back(i);
            i++;
            prev = prev -> next;
            temp = temp -> next;
        }

        if(cp.size() < 2) return {-1, -1};

        int mini = INT_MAX;
        for(int i=0;i<cp.size()-1;i++){
            mini = min(mini, cp[i+1]-cp[i]);
        }
        return {mini, (cp.back() - cp.front())};
    }
};