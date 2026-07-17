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
    void add(TreeNode* root,int &sum,vector<int> &t)
    {
        if(!root) return;

        t.push_back(root -> val);
        
        if(!root -> left && !root -> right) 
        {
            int num = 0;
            for(int i=0;i<t.size();i++)
            {
                num = num*10 + t[i];
            }
            sum += num;
            t.pop_back();
            return;
        }
        add(root -> left,sum,t);
        add(root -> right,sum,t);
        t.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        vector<int> t;

        add(root,sum,t);

        return sum;
    }
};