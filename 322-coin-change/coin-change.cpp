class Solution {
public:
    int findCoins(int i, int amount, vector<int>& coins, int n, vector<vector<int>> &dp){
        if(amount == 0) return 0;
        if(i >= n) return 1e7;
        if(dp[i][amount] != -1) return dp[i][amount];

        int notPick = findCoins(i+1, amount, coins, n, dp);
        int pick = 1e7;
        if(amount >= coins[i]){
            pick = 1 + findCoins(i, amount-coins[i], coins, n, dp);
        }

        return dp[i][amount] = min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int noOfCoins = findCoins(0, amount, coins, n, dp);

        return noOfCoins == 1e7 ? -1 : noOfCoins;
    }
};