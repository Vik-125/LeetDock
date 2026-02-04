class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
       
        int sum = 0;
        int l = 0;
        int r = 0;
        while(r < nums.size() && l < nums.size())
        {
            if(sum + nums[r] < target)
            {
                sum += nums[r];
                r++;
            }
            else 
            {
                sum-=nums[l];
                ans = min(ans,abs(r-l)+1);
                l++;
            }
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};