class Solution {
public:
    // Memoization

    // int findOps(string s, string t, int n1, int n2, vector<vector<int>> &dp){
    //     if(n1 < 0 || n2 < 0) return 0;
    //     if(dp[n1][n2] != -1) return dp[n1][n2];

    //     if(s[n1] == t[n2]){
    //         return dp[n1][n2] = 1 + findOps(s, t, n1-1, n2-1, dp);
    //     }
    //     return dp[n1][n2] = max(findOps(s, t, n1-1, n2, dp),findOps(s, t, n1, n2-1, dp));
    // }
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();

        vector<vector<int>> dp(l1+1,vector<int>(l2+1,-1));
        //int len = findOps(word1, word2, l1-1, l2-1, dp);



        // Tabulation


        // for(int i=0;i<=l1;i++) dp[i][0] = 0;
        // for(int j=0;j<=l2;j++) dp[0][j] = 0;

        // for(int i=1;i<=l1;i++){
        //     for(int j=1;j<=l2;j++){
        //         if(word1[i-1] == word2[j-1]){
        //             dp[i][j] = 1 + dp[i-1][j-1];
        //         }
        //         else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        //     }
        // }
        // int len = dp[l1][l2];
        vector<int> prev(l2+1,0), curr(l2+1,0);

        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(word1[i-1] == word2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else curr[j] = max(prev[j],curr[j-1]);
            }
            prev = curr;
        }

        int len = prev[l2];
        cout << len;
        return (l1+l2) - (2*len);
    }
};