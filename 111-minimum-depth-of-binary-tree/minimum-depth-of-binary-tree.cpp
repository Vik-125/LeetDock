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
    void check(TreeNode* root , int &mini,int height){
        if(!root) return;
        if(!root -> left && !root -> right)
        {
            mini = min(mini,height);
            return;
        }
        check(root -> left,mini,height+1);
        check(root -> right,mini,height+1);

        return;
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int mini = INT_MAX;
        int height = 1;

        check(root,mini,height);
        return mini;
    }
};