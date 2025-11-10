class Solution {
public:
    void dfs(int node,vector<vector<int>>& graph,vector<vector<int>> &ans,vector<int> &way,int V)
    {
        way.push_back(node);
        if(node == V-1){
            ans.push_back(way);
            way.pop_back();
            return;
        }
        for(auto neighbour : graph[node])
        {
            dfs(neighbour,graph,ans,way,V);
        }
        way.pop_back();
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> ans;
        vector<int> way;

        dfs(0,graph,ans,way,V);
        return ans;
    }
};