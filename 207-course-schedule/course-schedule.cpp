class Solution {
public:
    bool dfs(int node,vector<bool>& vis,vector<vector<int>> &adj,stack<int>&s,vector<int>&path)
    {
        vis[node] = true;
        path[node] = 1;

        for(auto &it : adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,adj,s,path)) return true;
            }
            else if(path[it]) return true;
        }
        s.push(node);
        path[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses,false);
        vector<vector<int>> adj(numCourses);
        stack<int> s;
        vector<int> path(numCourses,0);

        for(auto it : prerequisites)
        {
            int a = it[0],b = it[1];
            adj[b].push_back(a);
        }

        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,adj,s,path)) return false;
            }
        }

        return (s.size() == numCourses);
    }
};