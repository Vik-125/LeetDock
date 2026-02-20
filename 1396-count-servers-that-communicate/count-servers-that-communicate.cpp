class Solution {
public:
    int dfs(int r,int c,int n,int m,vector<vector<bool>>& vis,vector<vector<int>>& grid)
    {
        vis[r][c] = true;
        int cnt = 1;

        for(int i=0;i<n;i++)
        {
            if(grid[i][c] == 1 && !vis[i][c])
            {
                cnt += dfs(i,c,n,m,vis,grid);
            }
        }
        for(int j=0;j<m;j++)
        {
            if(grid[r][j] == 1 && !vis[r][j])
            {
                cnt += dfs(r,j,n,m,vis,grid);
            }
        }
        return cnt;
    }
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j] == 1) 
                {
                    int k = dfs(i,j,n,m,vis,grid);
                    if(k != 1) ans += k;
                }
            }
        }
        return ans;
    }
};