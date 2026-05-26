class Solution {
public:
    int find(int r,int c,int R,int C,vector<vector<int>>& grid,vector<vector<int>> &dp){
        if(r >= R || c >= C) return INT_MAX;
        if(r == R-1 && c == C-1) return dp[r][c] = grid[r][c];
        if(dp[r][c] != -1) return dp[r][c];

        int right = find(r,c+1,R,C,grid,dp);
        int down = find(r+1,c,R,C,grid,dp);

        return dp[r][c] = grid[r][c] + min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return find(0,0,m,n,grid,dp);
    }
};