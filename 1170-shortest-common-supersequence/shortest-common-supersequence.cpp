class Solution {
public:
    // int findLCSLength(string str1, string str2, int n1, int n2,
    //                   vector<vector<int>>& dp) {
    //     if (n1 == 0 || n2 == 0)
    //         return 0;
    //     if (dp[n1][n2] != -1)
    //         return dp[n1][n2];

    //     if (str1[n1 - 1] == str2[n2 - 1]) {
    //         return dp[n1][n2] =
    //                    1 + findLCSLength(str1, str2, n1 - 1, n2 - 1, dp);
    //     }
    //     return dp[n1][n2] = max(findLCSLength(str1, str2, n1 - 1, n2, dp),;
    //                             findLCSLength(str1, str2, n1, n2 - 1, dp));
    // }
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        string result = "";

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        // int len = findLCSLength(str1, str2, n1, n2, dp);

        for(int i=0;i<=n1;i++) dp[i][0] = 0;
        for(int j=0;j<=n2;j++) dp[0][j] = 0;

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
                }
            }
        }

        int len = dp[n1][n2];
        cout << len;
        cout << (n1 + n2 - len);

        while (n1 > 0 && n2 > 0) {
            if (str1[n1 - 1] == str2[n2 - 1]) {
                result += str1[n1 - 1];
                n1--;
                n2--;
            } else if (dp[n1 - 1][n2] > dp[n1][n2 - 1]) {
                result += str1[n1 - 1];
                n1--;
            } else {
                result += str2[n2 - 1];
                n2--;
            }
        }
        if (n1 == 0 && n2 == 0) {
            reverse(result.begin(), result.end());
            
            return result;
        } else if (n1 == 0 && n2 > 0) {
            while (n2 > 0) {
                result += str2[n2 - 1];
                n2--;
            }
        }

        else if (n1 > 0 && n2 == 0) {
            while (n1 > 0) {
                result += str1[n1 - 1];
                n1--;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};