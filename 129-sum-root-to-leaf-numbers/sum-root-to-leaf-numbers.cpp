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
    void add(TreeNode* root, int &sum, int &num)
    {
        if(!root) return;

        if(!root -> left && !root -> right) 
        {
            num = num*10 + root -> val;
            cout << num << " ";
            sum += num;

            num /= 10;
            return;
        }
        num = num*10 + root -> val;

        add(root -> left, sum, num);
        add(root -> right, sum, num);
        num /= 10;
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        vector<int> t;
        int num = 0;

        add(root, sum, num);

        return sum;
    }
};