/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "#";
        queue<TreeNode*> q;
        q.push(root);
        string mid;

        while(!q.empty())
        {
            int s = q.size();
            for(int i=0;i<s;i++)
            {
                TreeNode* t = q.front();
                q.pop();

                if(t == NULL)
                {
                    mid += "#,";
                }
                else 
                {
                    mid += to_string(t -> val) + ",";
                    q.push(t -> left);
                    q.push(t -> right);
                }
            }
        }
        return mid;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0 || data == "#") return NULL;
        
        stringstream ss(data);
        string str;
        getline(ss,str,',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            getline(ss,str,',');
            if(str == "#")
            {
                node -> left = NULL;
            }
            else 
            {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node -> left = leftNode;
                q.push(leftNode);
            }
            getline(ss,str,',');
            if(str == "#")
            {
                node -> right = NULL;
            }
            else 
            {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node -> right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));