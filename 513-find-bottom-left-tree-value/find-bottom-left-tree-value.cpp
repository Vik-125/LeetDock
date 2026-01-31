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
    int bestVal = 0;
    int bestDepth = -1;
    void check(TreeNode* root,int lvl)
    {
        if(!root) return;
        check(root -> left,lvl+1);
        if(lvl > bestDepth)
        {
            bestVal = root -> val;
            bestDepth = lvl;
        }
        check(root -> right,lvl+1);
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        check(root,0);
        return bestVal;
    }
};