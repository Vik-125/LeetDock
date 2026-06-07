class Solution {
public:
    // bool find(int i, int n, vector<int> &nums, int sum, int currSum, vector<vector<int>> &dp){
    //     if(currSum == sum) return true;
    //     if(i == n) return false;
    //     if(dp[i][currSum] != -1) return dp[i][currSum];

    //     bool pick = find(i+1, n, nums, sum, currSum+nums[i], dp);
    //     bool nPick = find(i+1, n, nums, sum, currSum, dp);

    //     return dp[i][currSum] = (pick || nPick);
    // }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int &it : nums) sum += it;

        vector<vector<bool>> dp(n,vector<bool> (sum+1,false));
        if(sum % 2 != 0) return false;
        else
        {
            for(int i=0;i<n;i++) dp[i][0] = true;
            if(nums[0] <= (sum/2)) dp[0][nums[0]] = true;
            
            for(int i=1;i<n;i++){
                for(int target = 1;target <= (sum/2) ;target++){
                    bool notTake = dp[i-1][target];
                    bool take = false;
                    if(nums[i] <= target){
                        take = dp[i-1][target-nums[i]];
                    }
                    dp[i][target] = take || notTake;
                }
            }
        }
        return dp[n-1][sum/2];
    }
};