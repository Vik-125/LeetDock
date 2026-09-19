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
    TreeNode* build(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int,int> &inMap){
        if(preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inIndex = inMap[root -> val];
        int numsForLeft = inIndex - inStart;

        root -> left = build(preorder, inorder, preStart + 1, preStart + numsForLeft, inStart, inIndex-1, inMap);

        root -> right = build(preorder, inorder, preStart + numsForLeft+ 1, preEnd, inIndex + 1, inEnd, inMap);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int, int> inMap;
        for(int i=0;i<n;i++){
            inMap[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, n-1, 0, n-1, inMap);
    }
};