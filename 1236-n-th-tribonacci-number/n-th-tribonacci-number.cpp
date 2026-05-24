class Solution {
public:
    int trib(int n,vector<int> &dp){
        if(dp[n] != -1) return dp[n];
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;
        return dp[n] = trib(n-1,dp) + trib(n-2,dp) + trib(n-3,dp);
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return trib(n,dp);
    }
};