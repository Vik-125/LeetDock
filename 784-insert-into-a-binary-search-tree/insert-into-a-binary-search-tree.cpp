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
        TreeNode* curr = root;
        if(!root){
            TreeNode* mid = new TreeNode(val);
            root = mid;
            return root;
        }

        while(curr)
        {
            if(curr -> val < val && curr -> right) curr = curr -> right;
            if(curr -> val < val && !curr -> right)
            {
                TreeNode* mid = new TreeNode(val);
                curr -> right = mid;
                return root;
            }
            if(curr -> val > val && curr -> left) curr = curr -> left;
            if(curr -> val > val && !curr -> left) 
            {
                TreeNode* mid = new TreeNode(val);
                curr -> left = mid;
                return root;
            }
        }
        return root;
    }
};