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
    int check(TreeNode* root)
    {
        if(!root) return 0;
        return 1 + max(check(root->left),check(root->right));
    }
    int find(TreeNode* root,int cnt,int sum,int depth)
    {
        if(!root) return sum;
        if(cnt == depth)
        {
            sum += root->val;
            return sum;
        }
        return find(root->left,cnt+1,sum,depth) + find(root->right,cnt+1,sum,depth);
    }
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        int depth = check(root);
        int sum = 0;
        sum = find(root,1,sum,depth);
        return sum;
    }
};