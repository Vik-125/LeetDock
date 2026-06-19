class Solution {
public:
    bool findResult(string& s, string& p, int n, int m, vector<vector<int>> &dp) {
        if (n < 0 && m < 0) return true;
        if (m < 0 && n >= 0) return false;
        if (n < 0 && m >= 0){
            while(m >= 0){
                if(p[m] != '*') return false;
                m--;
            }
            return true;
        }
        if(dp[n][m] != -1) return dp[n][m];
        if (s[n] == p[m] || p[m] == '?') {
            return dp[n][m] = findResult(s, p, n - 1, m - 1, dp);
        } 
        else if (p[m] == '*') {
            return dp[n][m] = findResult(s, p, n, m - 1, dp) ||    findResult(s, p, n - 1, m, dp);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return findResult(s, p, n - 1, m - 1, dp);
    }
};