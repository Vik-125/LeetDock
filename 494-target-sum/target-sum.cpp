class Solution {
public:
    int find(int i, vector<int>& nums, int target, int sum, vector<vector<int>> &dp, int totalSum) {
        if (i == nums.size()) {
            if (sum == target)
                return 1;
            else
                return 0;
        }
        if(dp[i][sum + totalSum] != -1) return dp[i][sum + totalSum];

        return dp[i][sum + totalSum] = find(i + 1, nums, target, sum + nums[i], dp, totalSum) +
                find(i + 1, nums, target, sum - nums[i], dp, totalSum);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto it : nums){
            sum+=it;
        }
        vector<vector<int>> dp(n,vector<int>(2*sum+1,-1));
        return find(0, nums, target, 0, dp, sum);
    }
};