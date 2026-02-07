class Solution {
public:
    int find(vector<int>& dp,vector<int> temp,int n)
    {
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int pick = find(dp,temp,n-2) + temp[n];
        int npick = find(dp,temp,n-1);
        return dp[n] = max(pick,npick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size()-1;
        if(n == 0) return nums[0];
        vector<int> temp1;
        vector<int> temp2;
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);

        for(int i=0;i<=n-1;i++) temp1.push_back(nums[i]);
        for(int i=1;i<=n;i++) temp2.push_back(nums[i]);
        return max(find(dp1,temp1,n-1),find(dp2,temp2,n-1));
    }
};