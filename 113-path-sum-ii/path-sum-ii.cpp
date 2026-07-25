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
    void find(TreeNode* root, int targetSum, vector<int> &temp,     vector<vector<int>> &result){
        if(!root) return;
        else if(targetSum - root -> val == 0 && !root -> right && !root -> left){
            temp.push_back(root -> val);
            result.push_back(temp);
            temp.pop_back();
            return;
        }
        targetSum -= root -> val;
        temp.push_back(root -> val);
        find(root -> left, targetSum, temp, result);
        find(root -> right, targetSum, temp, result);
        temp.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        vector<vector<int>> result;

        find(root, targetSum, temp, result);    
        return result;
    }
};