class Solution {
public:
    int fib(vector<int> &dp,int n)
    {
        if(dp[n] != 0) return dp[n];
        if(n == 1 || n == 2 || n == 0) return n;
        return dp[n] = fib(dp,n-1) + fib(dp,n-2);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        return fib(dp,n);
    }
};