class Solution {
public:
    // int find(string &s, string &t, int n, int m, vector<vector<int>> &dp){
    //     if(n < 0) return m+1;
    //     if(m < 0) return n+1;
    //     if(dp[n][m] != -1) return dp[n][m];

    //     if(s[n] == t[m]) return dp[n][m] = find(s, t, n-1, m-1, dp);

    //     return dp[n][m] = 1 + min({find(s, t, n, m-1, dp),find(s, t, n-1, m, dp),find(s, t, n-1, m-1, dp)});
    // }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
        // find(word1, word2, n-1, m-1, dp);


// Memoization for tabulation , i.e using 1-based indexing
        // if(n == 0) return m+1;
        // if(m == 0) return n+1;
        // if(dp[n][m] != -1) return dp[n][m];

        // if(s[n-1] == t[m-1]) return dp[n][m] = find(s, t, n-1, m-1, dp);

        // return dp[n][m] = 1 + min({find(s, t, n, m-1, dp),find(s, t, n-1, m, dp),find(s, t, n-1, m-1, dp)});

        for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int j=0;j<=m;j++) dp[0][j] = j;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
            }
        }
        return dp[n][m];
    }
};