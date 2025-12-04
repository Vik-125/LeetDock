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
    void check(TreeNode* root,int maxi,int &n)
    {
        if(!root) return;
        if(root -> val >= maxi) n+=1;
        maxi = max(maxi,root -> val);

        check(root -> left,maxi,n);
        check(root -> right,maxi,n);
        return;
    }
    int goodNodes(TreeNode* root) {
        int v = root -> val;
        int n = 0;

        check(root,v,n);
        return n;
    }
};