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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int ans = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,1});

        while(!q.empty())
        {
            int n = q.size();
            int mmin = q.front().second;
            int first,last;

            for(int i=0;i<n;i++){
                auto it = q.front().first;
                auto curr_id = q.front().second - mmin;
                q.pop();

                if(i == 0) first = curr_id;
                if(i == n-1) last = curr_id;
                if(it -> left) q.push({it -> left, 2*curr_id+1});
                if(it -> right) q.push({it -> right, 2*curr_id+2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};