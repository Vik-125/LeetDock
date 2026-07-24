/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int depth = 0;

        queue<pair<Node*,int>> q;
        q.push({root, 1});

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            int ch = top.first -> children.size();
            int l = top.second;

            for(int i=0;i<ch;i++){
                q.push({top.first -> children[i], l+1});
            }
            depth = max(depth, l);
        }
        return depth++;
    }
};