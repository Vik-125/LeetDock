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
    int diff = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        vector<int> arr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            arr.push_back(it -> val);

            if(it -> left) q.push(it -> left);
            if(it -> right) q.push(it -> right);
        }
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                diff = min(diff, abs(arr[i]-arr[j]));
            }
        }
        return diff;
    }
};