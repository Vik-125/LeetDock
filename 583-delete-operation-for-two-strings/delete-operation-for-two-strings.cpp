class Solution {
public:
    int findOps(string s, string t, int n1, int n2, vector<vector<int>> &dp){
        if(n1 < 0 || n2 < 0) return 0;
        if(dp[n1][n2] != -1) return dp[n1][n2];

        if(s[n1] == t[n2]){
            return dp[n1][n2] = 1 + findOps(s, t, n1-1, n2-1, dp);
        }
        return dp[n1][n2] = max(findOps(s, t, n1-1, n2, dp),findOps(s, t, n1, n2-1, dp));
    }
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();

        vector<vector<int>> dp(l1,vector<int>(l2,-1));
        int len = findOps(word1, word2, l1-1, l2-1, dp);
        cout << len;
        return (l1+l2) - (2*len);
    }
};