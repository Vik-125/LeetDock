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
    int check(TreeNode* root,TreeNode* parent,TreeNode* grandparent)
    {
        int sum = 0;
        if(!root) return 0;

        if(grandparent && grandparent->val % 2 == 0) sum += root -> val;

        sum += check(root -> left,root,parent);
        sum += check(root -> right,root,parent);

        return sum;
    }
    int sumEvenGrandparent(TreeNode* root) {
       return check(root,NULL,NULL);
    }
};