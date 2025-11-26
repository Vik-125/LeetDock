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
    pair<int,int> check(TreeNode* root,int &opt)
    {
        if(!root) return {0,0};

        auto [lsum,lcnt] = check(root -> left,opt);
        auto [rsum,rcnt] = check(root -> right,opt);

        int sum = lsum + rsum + root -> val;
        int cnt = lcnt + rcnt + 1;

        int avg = sum/cnt;
        if(avg == root -> val) opt++;
        return {sum,cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        int opt = 0;
        check(root,opt);
        return opt;
    }
};