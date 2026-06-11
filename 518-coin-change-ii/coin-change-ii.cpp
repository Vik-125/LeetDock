class Solution {
public:
    int findWays(int i, int amount, vector<int>& coins, vector<vector<int>> &dp){
        if(i == coins.size() || amount < 0) return 0;
        if(amount == 0) return 1;
        if(dp[i][amount] != -1) return dp[i][amount];

        int notPick = findWays(i+1, amount, coins, dp);
        int pick = 0;
        if(amount >= coins[i]){
            pick = findWays(i, amount-coins[i], coins, dp);
        }
        return dp[i][amount] = (pick + notPick);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        return findWays(0, amount, coins, dp);
    }
};