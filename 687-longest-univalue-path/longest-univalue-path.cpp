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
    int result = 0;
    int find(TreeNode* root){
        if(!root) return 0;
        // if(!root -> left && !root -> right) return 0;

        int l=0, r=0;

        l = find(root -> left);
        r = find(root -> right);

        if(root -> left){
            if(root -> val == root -> left -> val) l = l+1;
            else l = 0;
        }
        if(root -> right){
            if(root -> val == root -> right -> val) r = r+1;
            else r = 0;
        }
        result = max(result, l+r);
        return max({l, r});
    }
    int longestUnivaluePath(TreeNode* root) {
        find(root);
        return result;
    }
};