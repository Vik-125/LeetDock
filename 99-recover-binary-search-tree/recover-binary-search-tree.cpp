/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &temp){
        if(!root) return;

        inorder(root -> left, temp);
        temp.push_back(root -> val);
        inorder(root -> right, temp);
        return;
    }
    void check(TreeNode* root, int first, int second){
        if(!root) return;
        if(root -> val == first){
            root -> val = second;
        }
        else if(root -> val == second){
            root -> val = first;
        }

        check(root -> left, first , second);
        check(root -> right, first , second);
        return;
    }
    void recoverTree(TreeNode* root) {
        vector<int> temp;
        inorder(root, temp);

        int first = 0;
        int second = 0;
        bool flag = false;
        for(int i=0;i<temp.size()-1;i++){
            if(temp[i] > temp[i+1] && !flag){
                first = i;
                second = i+1;
                flag = true;
            }
            else if(temp[i] > temp[i+1] && flag) second = i+1;
        }

        if(!flag) return;

        check(root, temp[first], temp[second]);

        return;
    }
};