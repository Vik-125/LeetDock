class Solution {
public:
    int find(vector<int> &dp,int n)
    {
        if(dp[n] != -1) return dp[n];
        if (n == 0) return dp[n] = 0;
        if(n == 1 || n == 2) return dp[n] = 1;
        return dp[n] = find(dp,n-1) + find(dp,n-2);
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        int ans = find(dp,n);

        return ans;
    }
};