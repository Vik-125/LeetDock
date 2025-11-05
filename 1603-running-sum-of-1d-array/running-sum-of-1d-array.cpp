class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        int sum = 0;
        for(int i=0;i<n;i++)
        {
            ans.push_back(nums[i] + sum);
            sum += nums[i];
        }

        return ans;
    }
};