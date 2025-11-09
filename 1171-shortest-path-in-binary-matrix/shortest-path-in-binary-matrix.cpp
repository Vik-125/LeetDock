class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        queue<pair<int,pair<int,int>>> q;

        int V = grid.size();
        if(V == 1 && grid[0][0] == 0) return 1;
        vector<vector<int>> dist(V,vector<int>(V,INT_MAX));
        dist[0][0] = 1;

        q.push({1,{0,0}});


        while(!q.empty())
        {
            auto it = q.front();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            q.pop();

            for(int i=-1;i<=1;i++)
            {
                int nrow = r + i;
                for(int j=-1;j<=1;j++)
                {
                    int ncol = c + j;

                    if(nrow < V && ncol < V && nrow >= 0 && ncol >= 0 && grid[nrow][ncol] == 0 && 1 + dis < dist[nrow][ncol]) 
                    {
                        dist[nrow][ncol] = 1 + dis;
                        if(nrow == V-1 && ncol == V-1) return dis + 1;
                        q.push({1+dis,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};