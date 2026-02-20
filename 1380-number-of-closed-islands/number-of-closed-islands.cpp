class Solution {
public:
    bool dfs(int r,int c,int delr[],int delc[],vector<vector<bool>> &vis,int m,int n,vector<vector<int>>& grid)
    {
        vis[r][c] = true;
        bool isClosed = true;

        if(r == 0 || r == n-1 || c == 0 || c == m-1) isClosed = false;

        for(int i=0;i<4;i++)
        {
            int ro = r + delr[i];
            int co = c + delc[i];
            if(ro >= 0 && co >= 0 && ro < n && co < m)
            {
                if((ro == 0 || ro == n-1 || co == 0 || co == m-1) && grid[ro][co] == 0) isClosed = false;
                if(!vis[ro][co] && grid[ro][co] == 0)
                {
                    bool childClosed = dfs(ro,co,delr,delc,vis,m,n,grid);
                    if(!childClosed) isClosed = false;
                }
            }
        }
        return isClosed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        int delr[] = {-1,0,1,0};
        int delc[] = {0,-1,0,1};

        int cnt = 0;

        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(!vis[i][j] && grid[i][j] == 0)
                {
                    if(dfs(i,j,delr,delc,vis,m,n,grid)) cnt++;
                }
            }
        }
        return cnt;
    }
};