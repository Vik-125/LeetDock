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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> maxs;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int s = q.size();
            int maxi = INT_MIN;

            for(int i=0;i<s;i++){
                auto it = q.front();
                q.pop();

                maxi = max(maxi, it -> val);

                if(it -> left) q.push(it -> left);
                if(it -> right) q.push(it -> right);
            }
            maxs.push_back(maxi);
        }
        return maxs;
    }
};