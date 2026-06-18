class Solution {
public:
    int find(string &s, string &t, int n, int m, vector<vector<int>> &dp){
        if(n < 0) return m+1;
        if(m < 0) return n+1;
        if(dp[n][m] != -1) return dp[n][m];

        if(s[n] == t[m]) return dp[n][m] = find(s, t, n-1, m-1, dp);

        return dp[n][m] = 1 + min({find(s, t, n, m-1, dp),find(s, t, n-1, m, dp),find(s, t, n-1, m-1, dp)});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int> (m,-1));
        return find(word1, word2, n-1, m-1, dp);
    }
};