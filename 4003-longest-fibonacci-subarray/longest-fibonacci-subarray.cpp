class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 2;
        int len = 2;

        for(int i=2;i<n;i++)
        {
            if(nums[i] == nums[i-1] + nums[i-2])
            {
                ans = max(ans,len += 1);
            }
            else len = 2;
        }
        return ans;
    }
};