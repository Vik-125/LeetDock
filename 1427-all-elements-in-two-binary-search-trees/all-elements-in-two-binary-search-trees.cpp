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
    void trav(TreeNode* r,vector<int> &res)
    {
        if(!r) return;
        trav(r -> left,res);
        res.push_back(r -> val);
        trav(r -> right,res);
        return;
    }
    vector<int> merge(vector<int> &res1,vector<int> &res2)
    {
        vector<int> merged;
        int i=0,j=0;
        if(res1.size() == 0 && res2.size() == 0) return {};
        while(i < res1.size() && j < res2.size())
        {
            if(res1[i] < res2[j]) merged.push_back(res1[i++]);
            else merged.push_back(res2[j++]);
        }
        while(i < res1.size()) merged.push_back(res1[i++]);
        while(j < res2.size()) merged.push_back(res2[j++]);
        return merged;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res1;
        vector<int> res2;
        trav(root1,res1);
        trav(root2,res2);

        return merge(res1,res2);
    }
};