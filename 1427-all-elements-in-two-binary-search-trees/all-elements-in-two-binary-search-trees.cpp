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
    void in(TreeNode* r,vector<int> &res)
    {
        if(!r) return;
        res.push_back(r -> val);
        in(r -> left,res);
        in(r -> right,res);
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        in(root1,res);
        in(root2,res);

        sort(res.begin(),res.end());
        return res;
    }
};