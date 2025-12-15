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
    void leaf(TreeNode* root,vector<int> &t)
    {
        if(!root) return;
        if(!root -> left && !root -> right) t.push_back(root -> val);

        leaf(root -> left,t);
        leaf(root -> right,t);

        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t1;
        vector<int> t2;

        leaf(root1,t1);
        leaf(root2,t2);

        if(t1.size() != t2.size()) return false;

        for(int i=0;i<t1.size();i++)
        {
            if(t1[i] != t2[i]) return false;
        }
        return true;
    }
};