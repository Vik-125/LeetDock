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
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr) return {};
        vector<vector<int>> result;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int s = q.size();
            vector<int> mid;

            for(int i=0;i<s;i++){
                auto it = q.front();
                q.pop();

                mid.push_back(it -> val);
                for(auto i : it->children){
                    q.push(i);
                }
            }
            result.push_back(mid);
        }
        return result;
    }
};