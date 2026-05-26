class Solution {
public:
    int find(int r,int c,int R,int C,vector<vector<int>> &obstacleGrid,vector<vector<long long>> &dp){
        if(r >= R || c >= C) return 0;
        if(obstacleGrid[r][c] == 1) return 0;
        if(r == R-1 && c == C-1) return 1;
        if(dp[r][c] != -1) return dp[r][c];
        int down = find(r+1,c,R,C,obstacleGrid,dp);
        int right = find(r,c+1,R,C,obstacleGrid,dp);

        return dp[r][c] = down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<long long>> dp(n,vector<long long>(m,-1));

        return find(0,0,n,m,obstacleGrid,dp);
    }
};