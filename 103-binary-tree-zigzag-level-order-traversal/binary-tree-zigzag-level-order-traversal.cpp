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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> result;
        
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;

        while(!q.empty()){
            int n = q.size();
            vector<int> temp;

            for(int i=0;i<n;i++){
                auto top = q.front();
                q.pop();

                if(top -> left) q.push(top -> left);
                if(top -> right) q.push(top -> right);

                temp.push_back(top -> val);
            }
            if(flag) result.push_back(temp);
            else{
                reverse(temp.begin(),temp.end());
                result.push_back(temp);
            }
            flag = !flag;
        }
        return result;
    }
};