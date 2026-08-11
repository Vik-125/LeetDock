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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long> sums;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int s = q.size();
            long long sum = 0;

            for(int i=0;i<s;i++){
                auto n = q.front();
                q.pop();

                if(n -> left) q.push(n -> left);
                if(n -> right) q.push(n -> right);

                sum += n -> val;
            }
            sums.push_back(sum);
        }
        sort(sums.begin(),sums.end());
        if(sums.size() < k) return -1;
        else return sums[sums.size() - k];
    }
};