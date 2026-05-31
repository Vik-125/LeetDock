class Solution {
public:
    bool find(int i, int n, vector<int> &nums, int sum, int currSum, vector<vector<int>> &dp){
        if(currSum == sum) return true;
        if(i == n) return false;
        if(dp[i][currSum] != -1) return dp[i][currSum];

        bool pick = find(i+1, n, nums, sum, currSum+nums[i], dp);
        bool nPick = find(i+1, n, nums, sum, currSum, dp);

        return dp[i][currSum] = (pick || nPick);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int &it : nums) sum += it;

        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        if(sum % 2 != 0) return false;
        return find(0, n, nums, sum/2, 0, dp);
    }
};