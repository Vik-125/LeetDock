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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>  q;
        q.push(root);
        int level = 0;

        while(!q.empty())
        {
            int sizee = q.size();
            vector<TreeNode*> mid;
            for(int i=0;i<sizee;i++)
            {
                auto it = q.front();
                q.pop();
                mid.push_back(it);

                if(it->left) q.push(it->left);
                if(it -> right) q.push(it -> right);
            }
            if(level % 2 != 0) 
            {
                int l = 0, r = mid.size() - 1;
                while (l < r) {
                    swap(mid[l]->val, mid[r]->val);
                    l++;
                    r--;
                }
            }
            level++;
        }
        return root;
    }
};