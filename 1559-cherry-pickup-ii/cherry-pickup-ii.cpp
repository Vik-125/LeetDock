class Solution {
public:
    int find(int r, int r1c, int r2c, int R, int C, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp) {
        if (r >= R)
            return INT_MIN;
        if (r1c < 0 || r2c < 0 || r1c >= C || r2c >= C)
            return INT_MIN;
        if (r == R - 1) {
            if (r1c == r2c)
                return grid[r][r1c];
            else
                return grid[r][r1c] + grid[r][r2c];
        }
        if(dp[r][r1c][r2c] != -1) return dp[r][r1c][r2c];

        int maxi = INT_MIN;
        int del[] = {-1, 0, 1};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int nextR1c = r1c+del[i];
                int nextR2c = r2c+del[j];

                if(nextR1c >= 0 && nextR2c >= 0 && nextR1c < C && nextR2c < C){
                    int cherries = (r1c == r2c) ? grid[r][r1c] 
                                                : grid[r][r1c] + grid[r][r2c];
                    cherries += find(r + 1, nextR1c, nextR2c, R, C, grid,dp);
                    maxi = max(maxi, cherries);
                }
            }
        }
        return dp[r][r1c][r2c] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return find(0, 0, m - 1, n, m, grid,dp);
    }
};