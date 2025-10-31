class Solution {
public:
    bool check(vector<vector<int>>& graph,vector<int>& color,int start)
    {
        queue<int> q;
        q.push(start);

        color[start] = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto it: graph[node])
            {
                // If the adkjacent node is not coloured yet.
                // you will give the opposite color of it's adjacent node to it.
                if(color[it] == -1)
                {
                    color[it] = 1 - color[node];
                    q.push(it);
                }
                // If the node is coloured 
                // then just check if it is same to it's adjacent node color.
                else if(color[it] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
       int n = graph.size();
       vector<int> color(n,-1);

       for(int i=0;i<n;i++)
       {
            if(color[i] == -1)
            {
                if(!check(graph,color,i))
                {
                    return false;
                }
            }
       }
       return true;
    }
};