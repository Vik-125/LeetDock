class Solution {
public:
    int mod = 1e9+7;
    int dfs(int i,int j,vector<vector<int>>& grid,int R,int C,int drow[],int dcol[],vector<vector<int>> &dp)
    {
        if(dp[i][j] != -1) return dp[i][j];

        long long count = 1;
        for(int k=0;k<4;k++)
        {
            int nr = i+drow[k];
            int nc = j+dcol[k];
            if(nr < R && nc < C && nr >= 0 && nc >= 0 && grid[i][j] < grid[nr][nc])
            {
                count = (count + dfs(nr, nc, grid,R,C, drow, dcol, dp)) % mod;
            }
        }
        dp[i][j] = count;
        return count;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        int drow[] = {0,-1,0,1};
        int dcol[] = {1,0,-1,0};

        long long total = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                total = (total + dfs(i,j,grid,n,m,drow,dcol,dp)) % mod;
            }
        }
        return total;
    }
};