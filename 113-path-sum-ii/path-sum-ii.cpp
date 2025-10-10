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
    vector<vector<int>> ans;
    void check(TreeNode* root,int tar,vector<int> path)
    {
        if(!root) return;

        path.push_back(root -> val);
        tar -= root -> val;

        if(!root -> left && !root -> right && tar == 0)
        {
            ans.push_back(path);
        }
        else
        {
            check(root -> left ,tar , path);
            check(root -> right,tar , path);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        check(root,targetSum,path);
        return ans;
    }
};