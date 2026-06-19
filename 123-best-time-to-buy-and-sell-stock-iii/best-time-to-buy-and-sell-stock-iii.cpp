class Solution {
public:
    int findMaxi(int i, int buy, int tran, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(tran == 0) return 0;
        if(i == prices.size()) return 0;
        if(dp[i][buy][tran] != -1) return dp[i][buy][tran];

        if(buy){
            int pick = -prices[i] + findMaxi(i+1, !buy, tran, prices, dp);
            int skip = findMaxi(i+1, buy, tran, prices, dp);
            return dp[i][buy][tran] = max(pick, skip);
        }
        else {
            int sell = prices[i] + findMaxi(i+1, !buy, tran-1, prices, dp);
            int skip = findMaxi(i+1, buy, tran, prices, dp);
            return dp[i][buy][tran] = max(skip, sell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return findMaxi(0, 1, 2, prices, dp);
    }
};