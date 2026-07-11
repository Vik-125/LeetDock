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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m,vector<int>(n,-1));

        int l = 0;
        int t = 0;
        int b = m-1;
        int r = n-1;

        while(l <= r && t <= b && head){
            for(int i=l;i<=r;i++){
                if(head){
                    matrix[t][i] = head -> val;
                    head = head -> next;
                }
                else break;
            
            }
            t++;
            for(int j=t;j<=b;j++){
                if(head){
                    matrix[j][r] = head -> val;
                    head = head -> next;
                }
                else break;
            }
            r--;
            for(int i=r;i>=l;i--){
                if(head){
                    matrix[b][i] = head -> val;
                    head = head -> next;
                }
                else break;
            }
            b--;
            for(int i=b;i>=t;i--){
                if(head){
                    matrix[i][l] = head -> val;
                    head = head -> next;
                }
                else break;
            }
            l++;
        }
        return matrix;
    }
};