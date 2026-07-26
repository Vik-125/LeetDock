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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int> temp;

            for(int i=0;i<n;i++){
                auto it = q.front();
                q.pop();

                if(it -> left) q.push(it -> left);
                if(it -> right) q.push(it -> right);

                temp.push_back(it -> val);
            }
            result.push_back(temp);
        }
        return result;
    }
};