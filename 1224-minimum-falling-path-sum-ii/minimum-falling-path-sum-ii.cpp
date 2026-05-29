class Solution {
public:
    int find(int r, int c, int R, vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(c < 0 || c >= R) return INT_MAX;
        if(r == 0) return grid[r][c];
        if(dp[r][c] != -1) return dp[r][c];

        int mini = INT_MAX;
        for(int i=0;i<R;i++){
            if(i == c) continue;
            int p = find(r-1,i,R,grid,dp);

            mini = min(p,mini);
        }

        return dp[r][c] = grid[r][c] + mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1));

        for(int i=n-1;i>=0;i--){
            mini = min(find(n-1,i,n,grid,dp),mini);
        }

        return mini;
    }
};