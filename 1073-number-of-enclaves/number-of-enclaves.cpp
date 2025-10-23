class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<bool>>& vis,int dcol[],int drow[],int maxR,int maxC)
    {
        vis[r][c] = true;
        for(int i=0;i<4;i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(nrow >= 0 && ncol >= 0 && nrow < maxR && ncol < maxC && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                dfs(nrow,ncol,grid,vis,dcol,drow,maxR,maxC);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};

        int count = 0;

        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] && grid[0][j] == 1)
            {
                dfs(0,j,grid,vis,dcol,drow,n,m);
            }
            if(!vis[n-1][j] && grid[n-1][j] == 1)
            {
                dfs(n-1,j,grid,vis,dcol,drow,n,m);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && grid[i][0] == 1)
            {
                dfs(i,0,grid,vis,dcol,drow,n,m);
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1)
            {
                dfs(i,m-1,grid,vis,dcol,drow,n,m);
            }
        }
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < m; j++) 
            {
                if(grid[i][j] == 1 && !vis[i][j]) 
                {
                    count++;
                }
            }
        }
        return count;
    }
};