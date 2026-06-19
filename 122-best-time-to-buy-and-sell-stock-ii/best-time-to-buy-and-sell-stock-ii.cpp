class Solution {
public:
    // Memoization

    // int findGain(vector<int>& prices, int i, bool buy, vector<vector<int>> &dp){
    //     if(i == prices.size()) return 0;
    //     if(dp[i][buy] != -1) return dp[i][buy];

    //     if(buy){ 
    //         int take = -prices[i] + findGain(prices, i+1, !buy, dp);
    //         int skip = findGain(prices, i+1, buy, dp);
    //         return dp[i][buy] = max(skip,take);
    //     }
    //     else { 
    //         int sell = prices[i] + findGain(prices, i+1, !buy, dp);
    //         int skip = findGain(prices, i+1, buy, dp);
    //         return dp[i][buy] = max(sell,skip);
    //     }
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // Memoization
        //vector<vector<int>> dp(n,vector<int>(2,-1));
        //return findGain(prices, 0, 1, dp);

        // Tabulation
        // vector<vector<int>> dp(n+1,vector<int>(2,0));
        // dp[n][0] = dp[n][1] = 0;
        // for(int i=n-1;i>=0;i--){
        //     for(int buy=0;buy<=1;buy++){
        //         if(buy){ 
        //             int take = -prices[i] + dp[i+1][0];
        //             int skip = dp[i+1][1];
        //             dp[i][1] = max(skip,take);
        //         }
        //         else { 
        //             int sell = prices[i] + dp[i+1][1];
        //             int skip = dp[i+1][0];
        //             dp[i][0] = max(sell,skip);
        //         }
        //     }
        // }

        // Space opt
        vector<int> ahead(2,0), curr(2,0);
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy){ 
                    int take = -prices[i] + ahead[0];
                    int skip = ahead[1];
                    curr[1] = max(skip,take);
                }
                else { 
                    int sell = prices[i] + ahead[1];
                    int skip = ahead[0];
                    curr[0] = max(sell,skip);
                }
            }
            ahead = curr;
        }
        return curr[1];
    }
};