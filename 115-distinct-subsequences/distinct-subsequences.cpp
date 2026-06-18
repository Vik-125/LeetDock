class Solution {
public:
    // int findSub(string s, string t, int n1, int n2, vector<vector<int>> &dp){
    //     if(n2 == 0) return 1;
    //     if(n1 == 0) return 0;
    //     if(dp[n1][n2] != -1) return dp[n1][n2];
    
    //     if(s[n1-1] == t[n2-1]){
    //         int pick = findSub(s, t, n1-1, n2-1, dp);
    //         int notPick = findSub(s, t, n1-1, n2, dp);
    //         return dp[n1][n2] = (pick + notPick);
    //     }
    //     return dp[n1][n2] = findSub(s, t, n1-1, n2, dp);
    // }
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

        for(int i=0;i<=n1;i++) dp[i][0] = 1;

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1] == t[j-1]){
                    long pick = dp[i-1][j-1];
                    long notPick = dp[i-1][j];
                    dp[i][j] = (pick + notPick);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n1][n2];
    }
};