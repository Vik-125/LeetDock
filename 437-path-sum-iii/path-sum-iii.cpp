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
    void find2(TreeNode* root, long long targetSum, int &counter){
        if(!root) return;

        else if((long long)targetSum - root -> val == 0){
            counter++;
        }
        (targetSum -= root -> val);

        if(root -> left) find2(root -> left, targetSum, counter);
        if(root -> right) find2(root -> right, targetSum, counter);

        return;
    }
    void find(TreeNode* root, int targetSum, int &counter){
        if(!root) return;

        find2(root, targetSum, counter);

        if(root -> left) find(root -> left, targetSum, counter);
        if(root -> right) find(root -> right, targetSum, counter);

        return;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int counter = 0;
        find(root, targetSum, counter);

        return counter;
    }
};