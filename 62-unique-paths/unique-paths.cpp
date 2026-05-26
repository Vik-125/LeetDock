class Solution {
public:
    int check(int r,int c,int R,int C,vector<vector<int>> &dp)
    {
        if (r >= R || c >= C) return 0;
        if (r == R-1 || c == C-1) return 1;
        if (dp[r][c] != -1) return dp[r][c];
        
        int down = check(r+1,c,R,C,dp);
        int right = check(r,c+1,R,C,dp);
        
        return dp[r][c] = down+right;
    }
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
        return check(0,0,m,n,dp);
    }
};