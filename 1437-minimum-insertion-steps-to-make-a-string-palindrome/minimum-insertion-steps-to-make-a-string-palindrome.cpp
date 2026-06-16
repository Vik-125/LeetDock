class Solution {
public:
    // int findPalin(string &s, string &t, int n1, int n2, vector<vector<int>> &dp){
    //     if(n1 == 0 || n2 == 0) return 0;
    //     if(dp[n1][n2] != -1) return dp[n1][n2];

    //     if(s[n1-1] == t[n2-1]){
    //         return 1 + findPalin(s, t, n1-1, n2-1,dp);
    //     }
    //     return dp[n1][n2] = max(findPalin(s, t, n1-1, n2, dp), findPalin(s, t, n1, n2-1, dp));

    // }
    int minInsertions(string s) {
       string t = s;
       reverse(t.begin(),t.end());

       int n = s.size();

       //vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

       // int len = findPalin(s, t, n, n, dp);


       // Tabulation
    //    for(int i=0;i<=n;i++) dp[i][0] = 0;
    //    for(int j=0;j<=n;j++) dp[0][j] = 0;

    //    for(int i=1;i<=n;i++){
    //         for(int j=1;j<=n;j++){
    //             if(s[i-1] == t[j-1]){
    //                 dp[i][j] = 1 + dp[i-1][j-1];
    //             }
    //             else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    //         }
    //    }
    //   int len = dp[n][n];

    vector<int> prev(n+1,0), curr(n+1,0);

    for(int i=0;i<=n;i++) curr[0] = 0;

       for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
       }
       int len = curr[n];
       cout << len;
       return n-len;
    }
};