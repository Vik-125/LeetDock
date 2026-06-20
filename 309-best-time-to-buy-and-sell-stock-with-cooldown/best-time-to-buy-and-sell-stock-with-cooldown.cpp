class Solution {
public:
    int findProfit(int i, int buy, vector<int> &prices, vector<vector<int>> &dp){
        if(i >= prices.size()) return 0;
        if(dp[i][buy] != 0) return dp[i][buy];
        if(buy){
            int take = -prices[i] + findProfit(i+1, 0, prices, dp);
            int pass = findProfit(i+1, 1, prices, dp);
            return dp[i][buy] = max(pass, take);
        }
        else 
        {
            int sell = prices[i] + findProfit(i+2, 1, prices, dp);
            int pass = findProfit(i+1, 0, prices, dp);
            return dp[i][buy] = max(pass,sell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,0));
        return findProfit(0, 1, prices, dp);
    }
};