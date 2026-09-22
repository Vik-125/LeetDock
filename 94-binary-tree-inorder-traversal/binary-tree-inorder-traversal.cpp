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
    void trav(vector<int> &ans,TreeNode* root)
    {
        if(!root) return;
        trav(ans,root -> left);
        ans.push_back(root -> val);
        trav(ans,root -> right);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        trav(ans,root);
        return ans;
    }
};