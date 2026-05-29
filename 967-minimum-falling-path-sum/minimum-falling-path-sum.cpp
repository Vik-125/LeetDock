class Solution {
public:
    // int find(int r, int c, int R, int C, vector<vector<int>>&
    // matrix,vector<vector<int>> &dp){
    //     if(c < 0 || c >= C) return INT_MAX;
    //     if( r < 0) return INT_MAX;
    //     if(r == 0) return matrix[r][c];
    //     if(dp[r][c] != -1) return dp[r][c];

    //     int up = find(r-1,c,R,C,matrix,dp);
    //     int left = find(r-1,c-1,R,C,matrix,dp);
    //     int right = find(r-1,c+1,R,C,matrix,dp);

    //     return dp[r][c] = matrix[r][c] + min({up,left,right});
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int j = 0; j < n; j++)
            dp[0][j] = matrix[0][j];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = dp[i - 1][j];
                int left = (j > 0) ? dp[i-1][j-1] : 1e9;
                int right = (j < n-1) ? dp[i-1][j+1] : 1e9;

                dp[i][j] = matrix[i][j] + min({up, left, right});
            }
        }
        int mini = dp[n-1][0];
        for (int i = 0; i < n; i++) {
            mini = min(mini, dp[n - 1][i]);
        }
        return mini;
    }
};