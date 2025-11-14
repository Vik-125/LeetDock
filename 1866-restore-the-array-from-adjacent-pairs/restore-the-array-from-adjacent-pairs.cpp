class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>> &adj,unordered_map<int,bool> &vis,vector<int> &arr)
    {
        vis[node] = true;
        arr.push_back(node);

        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis,arr);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        for(auto it : adjacentPairs)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int start = 0;
        vector<int> arr;
        unordered_map<int,bool> vis;

        for(auto&[node,neighbour] : adj)
        {
            if(neighbour.size() == 1) 
            {
                start = node;
                break;
            }
        }
        dfs(start,adj,vis,arr);
        return arr;
    }
};