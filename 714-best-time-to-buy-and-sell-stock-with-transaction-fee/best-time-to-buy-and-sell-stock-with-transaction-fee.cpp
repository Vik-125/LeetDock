class Solution {
public:
    int findProfit(int i, int buy, vector<int>&prices, int fee, vector<vector<int>> &dp){
        if(i == prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];

        if(buy){
            int take = -prices[i] + findProfit(i+1, 0, prices, fee, dp);
            int skip = findProfit(i+1, 1, prices, fee, dp);
            return dp[i][buy] = max(take, skip);
        }
        else {
            int sell = prices[i] + findProfit(i+1, 1, prices, fee, dp) - fee;
            int skip = findProfit(i+1, 0, prices, fee, dp);
            return dp[i][buy] = max(skip,sell);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n,vector<int>(2,-1));
        return findProfit(0, 1, prices, fee, dp);
    }
};