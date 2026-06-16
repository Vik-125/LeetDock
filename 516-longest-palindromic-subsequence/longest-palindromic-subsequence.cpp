class Solution {
public:
    // int findPalin(string s, string t, int n1, int n2, vector<vector<int>> &dp){
    //     if(n1 == 0 || n2 == 0) return 0;
    //     if(dp[n1][n2] != -1) return dp[n1][n2];

    //     if(s[n1-1] == t[n2-1]) {
    //         return 1 + findPalin(s, t, n1-1, n2-1, dp);
    //     }
    //     return max(findPalin(s, t, n1-1, n2, dp),findPalin(s, t, n1, n2-1, dp));
    // }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(s.begin(),s.end());
        int n = s.size();

        // Tabulation
        // vector<vector<int>> dp(n+1, vector<int>(n+1,-1));

        // for(int i=0;i<=n;i++) dp[i][0] = 0;
        // for(int j=0;j<=n;j++) dp[0][j] = 0;
    

        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         if(s[i-1] == t[j-1]) {
        //             dp[i][j] = 1 + dp[i-1][j-1];
        //             }
        //         else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        //     }
        // }

        vector<int> prev(n+1,0), cur(n+1,0) ;

        for(int i=0;i<=n;i++) cur[0] = 0;
    
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == t[j-1]) {
                    cur[j] = 1 + prev[j-1];
                    }
                else cur[j] = max(prev[j],cur[j-1]);
            }
            prev = cur;
        }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=n;j++){
        //         cout << dp [i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return cur[n];
    }
};