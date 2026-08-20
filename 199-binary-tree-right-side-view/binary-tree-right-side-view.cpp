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
    vector<int> rightSideView(TreeNode* root) {
        /*
        if(root == nullptr) return {};
        vector<int> result;

        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});

        int plevel = -1;

        while(!q.empty()){
            int k = q.size();

            for(int i=0;i<k;i++){
                auto it = q.front();
                q.pop();
                if(it.second > plevel){
                    result.push_back(it.first -> val);
                    plevel++;
                }
                if(it.first -> right){
                    q.push({it.first -> right, it.second+1});
                }
                if(it.first -> left){
                    q.push({it.first -> left, it.second+1});
                }
            }
        }
        return result;
        */


        if(root == nullptr) return {};
        
        vector<int> result;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int s = q.size();

            for(int i=0;i<s;i++){
                auto it = q.front();
                q.pop();

                if(i == s-1){
                    result.push_back(it -> val);
                }

                if(it -> left) q.push(it -> left);
                if(it -> right) q.push(it -> right);
            }
        }
        return result;
    }
};