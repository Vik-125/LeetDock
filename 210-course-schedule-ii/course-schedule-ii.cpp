class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<bool>&vis,stack<int>&s,vector<int> &path)
    {
        vis[node] = true;
        path[node] = 1;

        for(auto &it : adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,adj,vis,s,path)) return true;
            }
            else if(path[it])
            {
                return true;
            }
        }
        s.push(node);
        path[node] = 0;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses,false);
        vector<int> ans;
        stack<int> s;
        vector<vector<int>> adj(numCourses);
        vector<int> path(numCourses,0);

        for(auto &it : prerequisites)
        {
            int a = it[0],b = it[1];
            adj[b].push_back(a);
        }

        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis,s,path)) return {};
            }
        }

        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};