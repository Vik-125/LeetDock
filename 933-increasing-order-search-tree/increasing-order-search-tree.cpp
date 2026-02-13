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
    void store(TreeNode* root,vector<int> &arr)
    {
        if(!root) return;

        store(root -> left,arr);
        arr.push_back(root -> val);
        store(root -> right,arr);
        return;
    }
    TreeNode* build(vector<int> arr,int n,int i)
    {
        if(i == n) return NULL;

        TreeNode* root = new TreeNode(arr[i]);

        root -> right = build(arr,n,i+1);
        return root;
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> arr;
        store(root,arr);

        sort(arr.begin(),arr.end());
        int n = arr.size();

        return build(arr,n,0);
    }
};