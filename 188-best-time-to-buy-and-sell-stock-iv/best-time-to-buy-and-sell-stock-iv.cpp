class Solution {
public:
    int findProfit(int i, int buy, int k, vector<int> &prices, vector<vector<vector<int>>>& dp){
        if(k == 0 || i == prices.size()) return 0;
        if(dp[i][buy][k] != -1) return dp[i][buy][k];

        if(buy){
            int pick = -prices[i] + findProfit(i+1, 0, k, prices, dp);
            int nPick =  findProfit(i+1, 1, k, prices, dp);
            return dp[i][buy][k] = max(pick, nPick);
        }
        else {
            int sell = prices[i] +  findProfit(i+1, 1, k-1, prices, dp);
            int nSell =  findProfit(i+1, 0, k, prices, dp);
            return dp[i][buy][k] = max(sell, nSell);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2,vector<int>(k+1,-1)));
        return findProfit(0, 1, k, prices, dp);
    }
};