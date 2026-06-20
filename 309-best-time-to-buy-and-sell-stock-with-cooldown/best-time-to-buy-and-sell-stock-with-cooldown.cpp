class Solution {
public:
// Memoization
    // int findProfit(int i, int buy, vector<int> &prices, vector<vector<int>> &dp){
    //     if(i >= prices.size()) return 0;
    //     if(dp[i][buy] != 0) return dp[i][buy];
    //     if(buy){
    //         int take = -prices[i] + findProfit(i+1, 0, prices, dp);
    //         int pass = findProfit(i+1, 1, prices, dp);
    //         return dp[i][buy] = max(pass, take);
    //     }
    //     else 
    //     {
    //         int sell = prices[i] + findProfit(i+2, 1, prices, dp);
    //         int pass = findProfit(i+1, 0, prices, dp);
    //         return dp[i][buy] = max(pass,sell);
    //     }
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2,0));
        //return findProfit(0, 1, prices, dp);

        dp[n][0] = dp[n][1] = 0;

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    int take = -prices[i] + dp[i+1][0];
                    int pass = dp[i+1][1];
                    dp[i][buy] = max(pass, take);
                }
                else 
                {
                    int sell = prices[i] + dp[i+2][1];
                    int pass = dp[i+1][0];
                    dp[i][buy] = max(pass,sell);
                }
            }
        }

        vector<int> ahead(2,0), curr(2,0), sAhead(2,0);
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    int take = -prices[i] + ahead[0];
                    int pass = ahead[1];
                    curr[buy] = max(pass, take);
                }
                else 
                {
                    int sell = prices[i] + sAhead[1];
                    int pass = ahead[0];
                    curr[buy] = max(pass,sell);
                }
            }
            sAhead = ahead;
            ahead = curr;
        }
        return curr[1];
    }
};