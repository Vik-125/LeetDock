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
    void insertNode(TreeNode* root, vector<TreeNode*> &ar){
        if(!root) return;

        ar.push_back(root);

        insertNode(root -> left, ar);
        insertNode(root -> right, ar);

        return;
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> ar;
        
        insertNode(root, ar);

        TreeNode* dummy = new TreeNode(0, nullptr, root);

        int i = 0;
        int n = ar.size();

        while(i < n){
            dummy -> right = ar[i];
            ar[i] -> left = nullptr;

            dummy = dummy -> right;
            i++;
        }
        return;
    }
};