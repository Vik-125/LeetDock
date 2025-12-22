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
    int find(vector<int>& nums,int i,int right)
    {
        int maxIdx = i;
        while(i <= right)
        {
            if(nums[i] > nums[maxIdx]) maxIdx = i;
            i++;
        }
        return maxIdx;
    }
    TreeNode* build(vector<int>&nums,int left,int right)
    {
        if(left > right) return NULL;

        int maxIdx = find(nums,left,right);

        TreeNode* root = new TreeNode(nums[maxIdx]);

        root -> left = build(nums,left,maxIdx-1);
        root -> right = build(nums,maxIdx+1,right);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();

        return build(nums,0,n-1);
    }
};