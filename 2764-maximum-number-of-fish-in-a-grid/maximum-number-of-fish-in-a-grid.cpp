class Solution {
public:
    void dfs(int r,int c, int R,int C,vector<vector<bool>> &vis,vector<vector<int>> &grid,int &cnt,int drow[],int dcol[])
    {
        vis[r][c] = true;
        cnt += grid[r][c];

        for(int i=0;i<4;i++)
        {
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if(nr < R && nc < C && nr >= 0 && nc >= 0 && !vis[nr][nc] && grid[nr][nc] > 0)
            {
                dfs(nr,nc,R,C,vis,grid,cnt,drow,dcol);
            }
        }
        return;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        int fish = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j] > 0)
                {
                    int cnt = 0;
                    dfs(i,j,n,m,vis,grid,cnt,drow,dcol);
                    fish = max(cnt,fish);
                }
            }
        }
        return fish;
    }
};