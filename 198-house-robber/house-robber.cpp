class Solution {
public:
    int find(vector<int>&dp,vector<int>&nums,int n)
    {
        if(n == 0) return nums[n];
        if(n <= -1) return 0;
        if(dp[n] != -1) return dp[n];
        int pick = find(dp,nums,n-2) + nums[n];
        int npick = find(dp,nums,n-1);
        return dp[n] = max(pick,npick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int> dp(n+1,-1);
        return find(dp,nums,n);
    }
};