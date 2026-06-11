class Solution {
public:
    // int findCoins(int i, int amount, vector<int>& coins, int n, vector<vector<int>> &dp){
    //     if(amount == 0) return 0;
    //     if(i >= n) return 1e7;
    //     if(dp[i][amount] != -1) return dp[i][amount];

    //     int notPick = findCoins(i+1, amount, coins, n, dp);
    //     int pick = 1e7;
    //     if(amount >= coins[i]){
    //         pick = 1 + findCoins(i, amount-coins[i], coins, n, dp);
    //     }

    //     return dp[i][amount] = min(pick, notPick);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // tabulation
        // vector<vector<int>> dp(n,vector<int>(amount+1,1e7));
        // for(int i=0;i<n;i++) dp[i][0] = 0;

        // for(int t=1;t<=amount;t++){
        //     if(t % coins[0] == 0) dp[0][t] = t/coins[0];
        //     else dp[0][t] = 1e7;
        // }
        // for(int i=1;i<n;i++){
        //     for(int t=1;t<=amount;t++){
        //         int notPick = dp[i-1][t];
        //         int pick = 1e7;
        //         if(t >= coins[i]){
        //             pick = 1 + dp[i][t-coins[i]];
        //         }
        //         dp[i][t] = min(pick, notPick);
        //     }
        // }
        // int noOfCoins = dp[n-1][amount];


        // Space optimization
        vector<int> cur(amount+1,1e7), prev(amount+1,1e7);

        for(int j=0;j<=amount;j++){
            if(j % coins[0] == 0){
                prev[j] = j/coins[0];
            }
        }
        for(int i=1;i<n;i++){
            for(int amt=0;amt<=amount;amt++){
                int notPick = prev[amt];
                int pick = 1e7;
                if(coins[i] <= amt){
                    pick = 1 +  cur[amt - coins[i]];
                }

                cur[amt] = min(pick,notPick);
            }
            prev = cur;
        }
        int noOfCoins = prev[amount];
        return noOfCoins == 1e7 ? -1 : noOfCoins;
    }
};