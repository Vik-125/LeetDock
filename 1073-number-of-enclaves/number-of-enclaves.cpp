class Solution {
public:
    int dfs(int i,int j,int delr[],int delc[],vector<vector<bool>> &vis,vector<vector<int>> &grid,int R,int C)
    {
        vis[i][j] = 1;
        int cnt = 1;

        for(int k=0;k<4;k++)
        {
            int nr = i + delr[k];
            int nc = j + delc[k];

            if(nc >= 0 && nr >= 0 && nr < R && nc < C && grid[nr][nc] == 1 && !vis[nr][nc])
            {
                
                cnt += dfs(nr,nc,delr,delc,vis,grid,R,C);
            }
        }
        return cnt;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        int delr[] = {-1,0,1,0};
        int delc[] = {0,-1,0,1};

        int countOne = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1) countOne++;
            }
        }

        int free = 0;
        for(int i=0;i<n;i++)
        {
            if(grid[i][0] == 1 && !vis[i][0])
            {
                free += dfs(i,0,delr,delc,vis,grid,n,m);
            }
            if(grid[i][m-1] && !vis[i][m-1])
            {
                free += dfs(i,m-1,delr,delc,vis,grid,n,m);
            }
        }
        for(int j=0;j<m;j++)
        {
            if(grid[0][j] == 1 && !vis[0][j])
            {
                free += dfs(0,j,delr,delc,vis,grid,n,m);
            }
            if(grid[n-1][j] && !vis[n-1][j])
            {
                free += dfs(n-1,j,delr,delc,vis,grid,n,m);
            }
        }
        return countOne - free;        
    }
};