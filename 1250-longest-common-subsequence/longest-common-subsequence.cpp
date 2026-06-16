class Solution {
public:
    // int findLCS(string text1, string text2, int l1, int l2,
    //             vector<vector<int>>& dp) {
    //     if (l1 < 0 || l2 < 0) return 0;
        
    //     if (dp[l1][l2] != -1) return dp[l1][l2];
    //     if (text1[l1] == text2[l2]) {
    //         return 1 + findLCS(text1, text2, l1 - 1, l2 - 1, dp);
    //     }
    //     return dp[l1][l2] = max(findLCS(text1, text2, l1 - 1, l2, dp),
    //                           findLCS(text1, text2, l1, l2 - 1, dp));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int maxi = 0;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        //maxi = findLCS(text1, text2, l1 - 1, l2 - 1, dp);
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int j=0;j<=m;j++) dp[0][j] = 0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};