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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, unordered_map<int,int> &inMap, int inStart, int inEnd, int pStart, int pEnd){
        if(pStart > pEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[pEnd]);
        
        int inInd = inMap[root -> val];
        int eleForLeft = inInd - inStart;

        root -> left = build(inorder, postorder, inMap, inStart, inStart + eleForLeft -1, pStart, pStart + eleForLeft - 1);

        root -> right =  build(inorder, postorder, inMap, inInd + 1, inEnd, pStart + eleForLeft, pEnd - 1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        unordered_map<int,int> inMap;
        for(int i=0;i<n;i++){
            inMap[inorder[i]] = i;
        }

        return build(inorder, postorder, inMap, 0, n-1, 0, n-1);
    }
};