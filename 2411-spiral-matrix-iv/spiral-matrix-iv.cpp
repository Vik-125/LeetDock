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

        int top = 0;
        int left = 0;
        int right = n-1;
        int bottom = m-1;

        while(top <= bottom && left <= right){
            for(int i=left;i<=right;i++){
               if(head){
                    matrix[top][i] = head -> val;
                    head = head -> next;
               }
               else break;
            }
            top++;

            for(int j=top;j<=bottom;j++){
                if(head){
                    matrix[j][right] = head -> val;
                    head = head -> next;
                }
                else break;
            }
            right--;

            for(int k=right;k>=left;k--){
                if(head){
                    matrix[bottom][k] = head -> val;
                    head = head -> next;
                }
                else break;
            }
            bottom--;

            for(int l=bottom;l>=top;l--){
                if(head){
                    matrix[l][left] = head -> val;
                    head = head -> next;
                }
                else break;
            }
            left++;
        }
        return matrix;
    }
};