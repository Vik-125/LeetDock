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
    void check(TreeNode* root,vector<string> &ans,string &mid)
    {
        if(!root) return;

        int len = mid.size();

        if(!root -> left && !root -> right)
        {
            mid += to_string(root -> val);
            ans.push_back(mid);
            mid.resize(len);
            return;
        }
        mid += to_string(root -> val);
        mid += "->";
        check(root -> left,ans,mid);
        check(root -> right,ans,mid);
        mid.resize(len);
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string mid;
        check(root,ans,mid);
        return ans;
    }
};