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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newRoot = root;
        TreeNode* temp = new TreeNode(val);
        if(root == nullptr) return temp;


        while(root){
            if(root -> val > val && root -> left){
                root = root -> left;
            }
            else if(root -> val < val && root -> right) root = root -> right;
            else break;
        }
        if(root -> val > val) root -> left = temp;
        else root -> right = temp;
        return newRoot;
    }
};