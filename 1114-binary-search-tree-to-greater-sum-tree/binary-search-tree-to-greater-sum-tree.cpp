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
    void fill(TreeNode* root, vector<TreeNode*> &arr){
        if(!root) return;

        fill(root -> left, arr);
        arr.push_back(root);
        fill(root -> right, arr);
        return;
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return nullptr;

        vector<TreeNode*> arr;
        fill(root, arr);

        int n = arr.size();
        int sum = 0;
        for(int i=n-1;i>=0;i--){
            int k = arr[i] -> val;

            arr[i] -> val = k + sum;
            sum += k;
        }
        return root;
    }
};