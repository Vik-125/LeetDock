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
 struct Info {
    TreeNode* node;
    int depth;
    TreeNode* parent;
};
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<Info> q;
        q.push({root,0,NULL});

        TreeNode* parentX = nullptr;
        TreeNode* parentY = nullptr;
        int depthX = -1;
        int depthY = -1;

        while(!q.empty())
        {
            auto [node,depth,parent] = q.front();
            q.pop();

            if(node -> val == x)
            {
                parentX = parent;
                depthX = depth;
            }
            if(node -> val == y)
            {
                parentY = parent;
                depthY = depth;
            }
            if(node -> left)
            {
                q.push({node -> left,depth+1,node});
            }
            if(node -> right)
            {
                q.push({node -> right,depth+1,node});
            }
        }
        return depthX == depthY && parentX != parentY;
    }
};