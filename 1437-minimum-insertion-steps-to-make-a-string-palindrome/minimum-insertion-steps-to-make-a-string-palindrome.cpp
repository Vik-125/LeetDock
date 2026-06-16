class Solution {
public:
    int findPalin(string &s, string &t, int n1, int n2, vector<vector<int>> &dp){
        if(n1 == 0 || n2 == 0) return 0;
        if(dp[n1][n2] != -1) return dp[n1][n2];

        if(s[n1-1] == t[n2-1]){
            return 1 + findPalin(s, t, n1-1, n2-1,dp);
        }
        return dp[n1][n2] = max(findPalin(s, t, n1-1, n2, dp), findPalin(s, t, n1, n2-1, dp));

    }
    int minInsertions(string s) {
       string t = s;
       reverse(t.begin(),t.end());

       int n = s.size();
       vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

       int len = findPalin(s, t, n, n, dp);
       cout << len;
       return n-len;
    }
};